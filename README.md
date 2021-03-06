# Spinners++

C++ implementation of an elegant terminal spinner. This is a header only project that you can include in your project to show progress spinners on an ANSI compatible terminal. 

## Using 

To this this just download and include the header in your project. This uses std::thread so make sure to link the proper library. On Linux you can use `-lpthread` when building your project 

### Example 

```c++
#include "spinners.hpp"

int main() {
  jms::Spinner s("Doing something cool", jms::classic);
  s.start();

  //Do work
  s.finish(jms::FinishedState::SUCCESS, "Complete!");

  //Make my own animation
  jms::Animation a{80, {"[.....]","[O....]","[.O...]","[..O..]","[...O.]","[....O]"}};
  s.setAnimation(a);
  s.setText("A custom animation");
  s.start();

  this_thread::sleep_for(3s);
  s.finish(jms::FinishedState::SUCCESS, "Custom animation complete");

  return 0;
}
```

## License 
Copyright 2021 James M. Slocum

MIT license. 
