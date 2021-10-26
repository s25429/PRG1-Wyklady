#include <string>


struct Person {
  std::string imie, nazwisko, tytul;

  Person(std::string i, std::string n, std::string t) 
  : imie(i), nazwisko(n), tytul(t) {};

  virtual std::string to_string() const = 0;
};

std::string who_is_it(Person const &p) {
  return p.to_string();
}


struct Greeting {
  virtual std::string greet(Person const &p) const = 0;
};
