#include <string>

struct Student {
  std::string         imie;
  std::string         nazwisko;
  const std::string   nr_indeksu;
  unsigned short int  nr_semestru;
  float               srednia_ocen;

  Student() = default;

  std::string to_string() const;
};