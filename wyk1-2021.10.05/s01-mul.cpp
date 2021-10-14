#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  const int a = std::stoi(argv[1]);
  const int b = std::stoi(argv[2]);

  std::cout << (a * b) << std::endl;

  return 0;
}