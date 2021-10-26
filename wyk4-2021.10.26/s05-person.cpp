#include <iostream>
#include "include/Person.h"


struct Mr : Person {
  Mr(std::string i, std::string n) 
  : Person(i, n, "Mr") {};

  std::string to_string() const override;
};

struct Mrs : Person {
  Mrs(std::string i, std::string n) 
  : Person(i, n, "Mrs") {};

  std::string to_string() const override;
};

struct King : Person {
  King(std::string i, std::string n) 
  : Person(i, n, "King") {};

  std::string to_string() const override;
};

struct Queen : Person {
  Queen(std::string i, std::string n) 
  : Person(i, n, "Queen") {};

  std::string to_string() const override;
};


std::string Mr::to_string() const {
  return "Mr " + this->imie + " " + this->nazwisko;
}

std::string Mrs::to_string() const {
  return "Mrs " + this->imie + " " + this->nazwisko;
}

std::string King::to_string() const {
  return "King " + this->imie + " " + this->nazwisko;
}

std::string Queen::to_string() const {
  return "Queen " + this->imie + " " + this->nazwisko;
}


struct Hello : Greeting {
  std::string greet(Person const &p) const override {
    return "Hello " + p.imie + " " + p.tytul;
  }
};

struct Good_evening : Greeting {
  std::string greet(Person const &p) const override {
    return "Good Evening " + p.imie + " " + p.tytul;
  }
};

struct Farewell : Greeting {
  std::string greet(Person const &p) const override {
    return "Farewell " + p.imie + " " + p.tytul;
  }
};


int main() {
  Mr mr("Tomasz", "Pierwszy");
  Mrs mrs("Anna", "Druga");
  King king("Marcin", "Trzeci");
  Queen queen("Martyna", "Czwarta");

  std::cout << who_is_it(mr) << std::endl;
  std::cout << who_is_it(mrs) << std::endl;
  std::cout << who_is_it(king) << std::endl;
  std::cout << who_is_it(queen) << std::endl;

  Hello hello{};
  Good_evening good_evening{};
  Farewell farewell{};

  std::cout << hello.greet(mr) << std::endl;
  std::cout << good_evening.greet(mrs) << std::endl;
  std::cout << farewell.greet(king) << std::endl;
  
  return 0;
}