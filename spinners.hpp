#ifndef __SPINNERS_HPP
#define __SPINNERS_HPP

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <utility>
#include <mutex>
#include <chrono>

namespace jmslocum {


  class Animation {
    public : 
      Animation() = delete;
      Animation(const int& interval, const std::vector<std::string>& frames) 
        : interval{interval}, frames{frames} {}
      ~Animation() = default;

      Animation& operator=(Animation& o) {
        interval = o.interval;
        frames.swap(o.frames);
        return *this;
      }

      int getInterval() const { return interval; } 
      const std::vector<std::string>& getFrames() const { return frames; }



    private : 
      int interval;
      std::vector<std::string> frames;
  };

  static Animation classic = Animation(100, {"-", "\\", "|", "/"});
  static Animation dots = Animation(80, {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"});
  static Animation arrows = Animation(120, {"▹▹▹▹▹", "▸▹▹▹▹", "▹▸▹▹▹", "▹▹▸▹▹", "▹▹▹▸▹", "▹▹▹▹▸"});
  static Animation bounce = Animation(80, {"[    ]", "[=   ]", "[==  ]", "[=== ]", "[ ===]", "[  ==]", "[   =]", "[    ]", "[   =]", "[  ==]", "[ ===]", "[====]", "[=== ]", "[==  ]", "[=   ]"});

  class Spinner {
    public :
     
      Spinner() : text{""}, currentAnimation{dots} {}

      Spinner(const std::string& text) : text{text}, currentAnimation{dots} {}

      Spinner(const std::string& text, Animation& animation) : 
        text{text}, currentAnimation{animation} {}

      void setText(const std::string& text) {
        this->text = text;
      }

      void setAnimation(Animation& animation) {
        this->currentAnimation = animation;
      }

      void start() {
        success = false;
        partial = false;
        finished = false; 

        this->animationThread = std::thread(std::ref(*this));
      }

      void succeed() {
        success = true;
        finished = true;
      }

      void succeed(const std::string& text) {
        this->text = text;
        success = true;
        finished = true;
        animationThread.join();
      }


      void fail() {
        success = false;
        finished = true;
        animationThread.join();
      }

      void warning() {
        partial = true;
        success = false;
        finished = true;
        animationThread.join();
      }

      void operator()() const {
        int currentFrame = 0;
        int totalFrames;
        int interval;
        while(!finished) {
          interval = currentAnimation.getInterval();
          totalFrames = currentAnimation.getFrames().size();

          {
            clearLine();
            std::cout << "\r" << currentAnimation.getFrames()[currentFrame] << " " << text;
            std::flush(std::cout);
          }
          currentFrame++;
          currentFrame %= totalFrames;
          std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }

        //Clear the line and get ready for final output
        clearLine();

        if (success) {
          std::cout << "\r" << successSymbol << " " << text << std::endl;
        }
        else if (partial) {
          std::cout << "\r" << warnSymbol << " " << text << std::endl;
        }
        else {
          std::cout << "\r" << failSymbol << " " << text << std::endl;
        }
      }

      Spinner& operator=(Spinner&& o) {
        animationThread = std::move(o.animationThread);
        text = std::move(o.text);
        currentAnimation = o.currentAnimation;
        return *this;
      }

    private : 
      std::thread animationThread;
      std::string text;
      Animation& currentAnimation;
      bool finished = false;
      bool success = false;
      bool partial = false;

      const char* successSymbol = "✅";
      const char* failSymbol = "❌";
      const char* warnSymbol = "⚠";
      
      //Assumes ANSI terminal. 
      void clearLine() const {
        std::cout << "\33[2K";
      }
  };
};

#endif
