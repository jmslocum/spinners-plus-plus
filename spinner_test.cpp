#include "spinners.hpp"

#include <thread>
#include <string>
#include <chrono>
#include <sstream>

using namespace std;

int main() {
  jms::Spinner s("Doing cool stuff", jms::arrows);

  s.start();
  ostringstream oss; 
  for (int i = 0; i < 200; i++) {
    oss.str("");
    oss.clear();
    oss << "Doing cool stuff: " << i;
    s.setText(oss.str());
    this_thread::sleep_for(10ms);
  }

  s.succeed("yay, it works!");

  s = jms::Spinner("Now Starting the next task", jms::classic);
  s.start();

  this_thread::sleep_for(2s);
  s.setAnimation(jms::dots);
  this_thread::sleep_for(2s);

  s.fail("Failed to finish that task");

  s = jms::Spinner("Trying one more...", jms::bounce);
  s.start();

  this_thread::sleep_for(3s);
  s.warning("This task ended with a warning");

  //Make my own animation
  jms::Animation a{80, {"[.....]","[O....]","[.O...]","[..O..]","[...O.]","[....O]"}};
  s.setAnimation(a);
  s.setText("A custom animation");
  s.start();

  this_thread::sleep_for(3s);
  s.succeed("Custom animation complete");

  return 0;
}
