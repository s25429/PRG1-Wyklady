#include <iostream>
#include <string>
#include <random>

int main() {
  std::random_device rd;
  std::uniform_int_distribution<int> dice (1, 100);

  std::string guess_str = "";
  int guess_int = 0, 
      tries = 0,
      number = dice(rd);
  bool win = false;

  do {
    std::cout << "guess: ";
    std::getline(std::cin, guess_str);

    try { 
      guess_int = std::stoi(guess_str); 
      tries++;
    } catch (const std::invalid_argument& e) { 
      std::cout << "given input is not a number!\n";
      continue;
    }

    if (guess_int > number) {
      std::cout << "number too big!\n";
    } else if (guess_int < number)  {
      std::cout << "number too small!\n";
    } else {
      std::cout << "just right! You were correct on your " << tries << ". try\n";
      win = true;
    }
  } while (!win);

  return 0;
}