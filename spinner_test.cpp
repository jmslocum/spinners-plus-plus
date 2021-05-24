#include "spinners.hpp"

#include <thread>
#include <string>
#include <chrono>
#include <sstream>

using namespace std;

int main() {
  jms::Spinner s("uploading to satellite", jms::arrows);

  s.start();
  ostringstream oss; 
  for (int i = 0; i < 200; i++) {
    oss.str("");
    oss.clear();
    oss << "uploading to satellite: " << i;
    s.setText(oss.str());
    this_thread::sleep_for(10ms);
  }

  s.setText("downloading from satellite");
  s.setAnimation(jms::arrows_reverse);
  this_thread::sleep_for(3s);

  s.finish(jms::FinishedState::SUCCESS, "yay, it works!");

  s = jms::Spinner("Now Starting the next task", jms::classic);
  s.start();

  this_thread::sleep_for(2s);
  s.setAnimation(jms::dots);
  this_thread::sleep_for(2s);

  s.finish(jms::FinishedState::FAILURE, "Failed to finish that task");

  s = jms::Spinner("Trying one more...", jms::bounce);
  s.start();

  this_thread::sleep_for(3s);
  s.finish(jms::FinishedState::WARNING, "This task ended with a warning");

  s = jms::Spinner("Here is the toggle animation", jms::toggle);
  s.start();
  this_thread::sleep_for(3s);
  s.finish(jms::FinishedState::SUCCESS);

  s.setAnimation(jms::progress);
  s.setText("here is the progress animation");
  s.start();

  this_thread::sleep_for(3s);
  s.finish(jms::FinishedState::SUCCESS);

  //Make my own animation
  jms::Animation a{80, {"[.....]","[O....]","[.O...]","[..O..]","[...O.]","[....O]"}};
  s.setAnimation(a);
  s.setText("A custom animation");
  s.start();

  this_thread::sleep_for(3s);
  s.finish(jms::FinishedState::SUCCESS, "Custom animation complete");

  return 0;
}
