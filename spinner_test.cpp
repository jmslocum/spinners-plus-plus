#include "spinners.hpp"

#include <thread>
#include <string>
#include <chrono>
#include <sstream>

using namespace std;

int main() {
  jmslocum::Spinner s("Doing cool stuff", jmslocum::arrows);

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

  s = jmslocum::Spinner("Now Starting the next task", jmslocum::classic);
  s.start();

  this_thread::sleep_for(2s);
  s.setAnimation(jmslocum::dots);
  this_thread::sleep_for(2s);

  s.fail("Failed to finish that task");

  s = jmslocum::Spinner("Trying one more...", jmslocum::bounce);
  s.start();

  this_thread::sleep_for(3s);
  s.warning("This task ended with a warning");

  //Make my own animation
  jmslocum::Animation a{80, {"[.....]","[O....]","[.O...]","[..O..]","[...O.]","[....O]"}};
  s.setAnimation(a);
  s.setText("A custom animation");
  s.start();

  this_thread::sleep_for(3s);
  s.succeed("Custom animation complete");

  return 0;
}
