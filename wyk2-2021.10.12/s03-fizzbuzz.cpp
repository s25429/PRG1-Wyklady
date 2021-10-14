#include <iostream>
#include <string>

bool mod3(int v);
bool mod5(int v);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Nalezy podac jeden argument\n";
  } else {
    std::string msg = "";
    int n;

    try { n = std::stoi(argv[1]); }
    catch (const std::invalid_argument& e) { 
      std::cout << "Musisz podac liczbe!\n";
      return 1;
    }

    for (int i = 1; i <= n; i++, msg = "") {
      std::cout << i << " ";
      if (mod3(i)) msg += "Fizz";
      if (mod5(i)) msg += "Buzz";
      std::cout << msg << "\n";
    }
  }
  return 0;
}

bool mod3(int v) {
  return !(v % 3);
}

bool mod5(int v) {
  return !(v % 5);
}