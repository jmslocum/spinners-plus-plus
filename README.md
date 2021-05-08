# Spinners++

C++ implementation of an elegant terminal spinner. This is a header only project that you can include in your project to show progress spinners on an ANSI compatable terminal. 

## Using 

To this this just download and include the header in your project. This uses std::thread so make sure to link the proper libray. On linux you can use `-lpthread` when building your project 

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

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

