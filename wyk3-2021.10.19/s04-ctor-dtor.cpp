#include <iostream>
#include <string>

struct Struktura {
  std::string nazwa;
  Struktura(std::string n) : nazwa(n) {}
  ~Struktura() { std::cout << "DESTRUCTION! " << nazwa << std::endl; }
};

int main() {
  auto s = Struktura("jajko");

  return 0;
}