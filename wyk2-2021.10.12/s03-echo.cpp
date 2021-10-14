#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>


constexpr int OPT_SIZE = 3;
std::array<std::string, OPT_SIZE> options = { "-n", "-r", "-l" };
uint8_t flag = 0x00, // empty flag: 0000  |  To add: flag = flag | 0x01
        optN = 0x01, // option N:   0001  |  0x00 += 0x01 = 0x01
        optR = 0x02, // option R:   0010  |  To filter: flag = flag & 0x01
        optL = 0x04; // option L:   0100  |  0x05 & 0x01 = 0x01


void deleteFirstArgument(std::vector<std::string>& v);


int main(int argc, char* argv[]) {
  std::vector<std::string> result;
  std::vector<std::string> args(argv, argv + argc);
  deleteFirstArgument(args);

  bool opt_args = true; // Controls when option arguments end
  for (int i = 0; i < std::distance(args.begin(), args.end()); i++) {
    if (args[i].find("-") != std::string::npos && opt_args == true) {
      // Found option argument

      for (int j = 0; j < OPT_SIZE; j++) {
        if (options[j] == args[i]) {
          // Found specific argument

          flag |= (uint8_t)pow(2, j);
          break;
        }
      }
    } else {
      // Args[i] is not option argument - don't take in more option arguments
      opt_args = false;
    }

    if (!opt_args) result.push_back(args[i] + (flag & optL ? "\n" : " "));
  }

  if (!(flag & optN)) result.push_back("\n");
  if (flag & optR) std::reverse(result.begin(), result.end());

  for (const std::string& el : result)
    std::cout << el;

  return 0;
}

void deleteFirstArgument(std::vector<std::string>& v) {
  std::reverse(v.begin(), v.end());
  v.pop_back();
  std::reverse(v.begin(), v.end());
}
