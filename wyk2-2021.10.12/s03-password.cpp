#include <iostream>
#include <string>

int main() {
  std::string pwd = "student";
  std::string user_input = "";

  do {
    std::cout << "password: ";
    std::getline(std::cin, user_input);
  } while (pwd.compare(user_input) != 0);

  std::cout << "ok!\n";
  return 0;
}