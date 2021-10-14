#include <iostream>
#include <string>

bool func(bool flag, int i);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Nalezy podac jeden argument\n";
  } else {
    int x;
    try { x = std::stoi(argv[1]); }
    catch (const std::invalid_argument& e) { x = 0; }

    // Flag that checks if we should be incrementing or decrementing
    bool go_up = x < 0;

    for (int i = x; func(go_up, i); (go_up ? i++ : i--))
      std::cout << i << "...\n";
  }

  return 0;
}

bool func(bool flag, int i) {
  // Checks the range limit based on if we should go up or down
  if (flag) return i <= 0 ? true : false;
  else      return i >= 0 ? true : false;
}