#include <iostream>
#include <sstream>
#include "platform/platform.hpp"

int main(int argc, char const *argv[]) {
  
  // Init
  int steps = 1;
  bool verbose = 1;

  switch(argc) {
    case 3:
      std::istringstream(argv[2]) >> verbose;
      std::cout << std::boolalpha << verbose << std::endl;

    case 2:
      std::istringstream(argv[1]) >> steps;
      std::cout << steps << std::endl;

    default:
      break;
  }

  std::cout << "--- PLATFORM init ---" << std::endl;

  // Init a platform
  Platform p("testdata/platform.txt", steps, verbose);

  std::cout << "--- PLATFORM binding ---" << std::endl;
  // We bind all the components
  p.bind();

  std::cout << "--- PLATFORM simulation ---" << std::endl;
  // We do all the simulation
  p.simulate();

  std::cout << "--- end, bye ! ---" << std::endl;

  return 0;
}
