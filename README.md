# Spinners++

C++ implementation of an elegant terminal spinner. This is a header only project that you can include in your project to show progress spinners on an ANSI compatible terminal. 

## Using 

To this this just download and include the header in your project. This uses std::thread so make sure to link the proper library. On Linux you can use `-lpthread` when building your project 

### Example 

```c++
#include "spinners.hpp"

int main() {
  jmslocum::Spinner s("Doing something cool", jmslocum::classic);
  s.start();

  //Do work
  s.succeed("Complete!");

  //Make my own animation
  jmslocum::Animation a{80, {"[.....]","[O....]","[.O...]","[..O..]","[...O.]","[....O]"}};
  s.setAnimation(a);
  s.setText("A custom animation");
  s.start();

  this_thread::sleep_for(3s);
  s.succeed("Custom animation complete");

  return 0;
}
```

## License 
Copyright 2021 James M. Slocum

MIT license. 
