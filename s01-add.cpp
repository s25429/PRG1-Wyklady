#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  short int suma = 0;
  for (short unsigned int i = 1; i < argc; i++) {
    suma += std::stoi(argv[i]);
  }

  std::cout << suma << std::endl;

  return 0;
}