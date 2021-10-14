#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>


// Simple table of possible operators
std::vector<std::string> const operators_vector = { 
  "+", "-", "*", "/", "//", "%", "**", "sqrt", "!" 
};

// Class with enum that correspond to indeces in operators table
class Operators {
public:
  enum OperatorsEnum : int { 
    ADD = 0, SUB, MUL, DIV, FLOOR, MOD, POW, SQRT, FACT 
  };
};


int findOperator(std::string arg);
bool processCalculations(int opr, std::vector<double>& vect);
int factorial(int n);


int main(int argc, char* argv[]) {
  if (argc <= 1) {
    std::cout << "No arguments given\n";
    return 1;
  }

  // Where arguments given are stored
  auto args = std::vector<std::string>{};
  std::copy_n(argv, argc, std::back_inserter(args));
  args.erase(args.begin());

  // Where results are stored in double
  std::vector<double> res;

  for (auto const& arg : args) {
    try { 
      // Is a number
      res.push_back(std::stod(arg));
    } catch (const std::invalid_argument& e) { 
      // Is not a number
      int opr = findOperator(arg);
      bool success = processCalculations(opr, res);
      if(!success) {
        std::cout << "Given wrong input: " << arg << "\n";
        return 1;
      }
    }
  }

  std::cout << res[0] << "\n";
  return 0;
}

int findOperator(std::string arg) {
  // Checks if we found a valid operator in an argument
  for (int i = 0; i < (int)operators_vector.size(); i++)
    if (arg == operators_vector[i]) return i;
  return -1;
}

bool processCalculations(int opr, std::vector<double>& vect) {
  double result;

  switch(opr) {
    // Found a valid operator
    case Operators::ADD:
      result = vect[0] + vect[1];
      break;
    case Operators::SUB:
      result = vect[0] - vect[1];
      break;
    case Operators::MUL:
      result = vect[0] * vect[1];
      break;
    case Operators::DIV: 
      result = vect[0] / vect[1];
      break;
    case Operators::FLOOR: 
      result = floor(vect[0] / vect[1]);
      break;
    case Operators::MOD: 
      result = (int)vect[0] % (int)vect[1];
      break;
    case Operators::POW: 
      result = pow(vect[0], vect[1]);
      break;
    case Operators::SQRT: 
      result = sqrt(vect[0]);
      break;
    case Operators::FACT: 
      result = factorial((int)vect[0]);
      break;
    // Found an invalid operator
    default: return false;
  }

  vect.clear();
  vect.push_back(result);
  vect.shrink_to_fit();
  return true;
}

int factorial(int n) {
  int fact = 1;
  for (int i = 1; i <= n; i++) fact *= i;
  return fact;
}
