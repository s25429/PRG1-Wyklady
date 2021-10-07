#include <iostream>
#include <string>

auto getName() -> std::string;

int main(int argc, char* argv[]) {
  std::string name = argc == 2 ? argv[1] : getName();

  std::cout << "Hello " << name << "!\n";

  return 0;
}

auto getName() -> std::string {
  std::string name;
  printf("Podaj swoje imie: ");
  std::getline(std::cin, name);
  return name;
}