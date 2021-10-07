#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  short int a, b = 0;

  std::cout << "Podaj A: ";
  std::cin >> a;
  std::cout << "Podaj B:";
  std::cin >> b;

  std::cout << " = " << a - b << "\n";

  return 0;
}