#include <iostream>
#include "include/Student.h" // Nie potrzebuje #include<string> bo jest on uzyty juz w tym pliku


std::string Student::to_string() const {
  std::string imie = this->imie + " " + this->nazwisko;
  std::string indeks = "[nr: " + this->nr_indeksu + "]";
  std::string semestr = "Semestr " + std::to_string(this->nr_semestru);
  std::string srednia = "Srednia ocen: " + std::to_string(this->srednia_ocen);

  return imie + " " + indeks + "\n" + semestr + ". " + srednia + "\n";
}


int main() {
  Student stdn = Student{ "Jan", "Kowalski", "s11223", 1, 4.5 };

  std::cout << stdn.to_string() << std::endl;

  return 0;
}