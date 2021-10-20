#include <iostream>

struct Struktura {
  int value = 1;
  Struktura() = default;

  void ten() {
    std::cout << "Ten:\t" << this << std::endl;
  }
};

int main() {
  auto s = Struktura{};
  s.ten();

  std::cout << "Z main:\t" << &s << std::endl;

  return 0;
}