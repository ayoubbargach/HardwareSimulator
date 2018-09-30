#include <iostream>
#include <sstream>

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

  return 0;
}
