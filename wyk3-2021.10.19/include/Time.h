#include <stdexcept>
#include <string>

enum class Time_of_day {
  RANO, DZIEN, WIECZOR, NOC
};

std::string to_string(const Time_of_day& tod);

struct Czas {
private:
  unsigned short int godz, min, sek = 0;

  // Setters
  void setH(unsigned short int h);
  void setM(unsigned short int m);
  void setS(unsigned short int s);

public:
  // Constructor
  Czas(unsigned short int h, unsigned short int m, unsigned short int s);

  // Getters
  unsigned short int getH() const;
  unsigned short int getM() const;
  unsigned short int getS() const;

  // Methods
  std::string to_string() const;
  void next_hour();
  void next_minute();
  void next_second();
  std::string time_of_day() const;

  // Operator overloads
  Czas operator+ (const Czas& other) const;
  Czas operator- (const Czas& other) const;
  bool operator< (const Czas& other) const;
  bool operator> (const Czas& other) const;
  bool operator== (const Czas& other) const;
  bool operator!= (const Czas& other) const;

  // Other methods
  uint64_t count_seconds() const;
  uint64_t count_minutes() const;
  Czas time_to_midnight() const;
};