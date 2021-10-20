#include <iostream>
#include <set>
#include <math.h>
#include "include/Time.h"


std::string to_string(const std::set<Time_of_day>& tod) {
  if      (tod.count(Time_of_day::DZIEN))   return "Dzien";
  else if (tod.count(Time_of_day::NOC))     return "Noc";
  else if (tod.count(Time_of_day::WIECZOR)) return "Wieczor";
  else if (tod.count(Time_of_day::RANO))    return "Rano";
  else                                      return "A bo ja wiem";
}


Czas::Czas(unsigned short int h, unsigned short int m, unsigned short int s) {
  if (h > 24)       throw std::invalid_argument("Podana godzina za duza");
  else if (m > 60)  throw std::invalid_argument("Podane minuty za duze");
  else if (s > 60)  throw std::invalid_argument("Podane sekundy za duze");

  setH(h); setM(m); setS(s);
}

void Czas::setH(unsigned short int h) { godz = h % 24; }
void Czas::setM(unsigned short int m) { min = m % 60;  }
void Czas::setS(unsigned short int s) { sek = s % 60;  }

unsigned short int Czas::getH() const { return godz; }
unsigned short int Czas::getM() const { return min;  }
unsigned short int Czas::getS() const { return sek;  }

std::string Czas::to_string() const {
  std::string h = std::to_string(getH());
  std::string m = std::to_string(getM());
  std::string s = std::to_string(getS());

  if (getH() < 10) h.insert(0, "0");
  if (getM() < 10) m.insert(0, "0");
  if (getS() < 10) s.insert(0, "0");

  return h + ":" + m + ":" + s;
}

void Czas::next_hour()   { 
  setH(getH() + 1); 
}

void Czas::next_minute() { 
  unsigned short int new_m = getM() + 1;
  if (new_m == 60)
    next_hour();
  setM(new_m); 
}

void Czas::next_second() { 
  unsigned short int new_s = getS() + 1;
  if (new_s == 60) 
    next_minute();
  setS(new_s); 
}

std::string Czas::time_of_day() const {
  auto pora_dnia = std::set<Time_of_day>{};
  unsigned short int godzina = getH();
  
  if (godzina < 6) 
    pora_dnia.insert(Time_of_day::NOC);
  else if (godzina >= 6 && godzina < 12) 
    pora_dnia.insert(Time_of_day::RANO);
  else if (godzina >= 12 && godzina < 18)
    pora_dnia.insert(Time_of_day::DZIEN);
  else if (godzina >= 18 && godzina < 24)
    pora_dnia.insert(Time_of_day::WIECZOR);

  // Uzyj funckji to_string z globalnej puli
  extern std::string to_string(const std::set<Time_of_day>& tod);
  return to_string(pora_dnia);
}

Czas Czas::operator+ (const Czas& other) const {
  /* W dodawaniu uzylem wbudowanych funckji */
  auto new_obj = Czas{ this->getH(), this->getM(), this->getS() };
  unsigned short int  h = other.getH(), 
                      m = other.getM(), 
                      s = other.getS();
  unsigned short int i;
  for (i = 0; i < h; i++) new_obj.next_hour();
  for (i = 0; i < m; i++) new_obj.next_minute();
  for (i = 0; i < s; i++) new_obj.next_second();

  return new_obj;
}

Czas Czas::operator- (const Czas& other) const {
  short int h, m, s;
  h = this->getH() - other.getH();
  m = this->getM() - other.getM();
  s = this->getS() - other.getS();

  short int s_new = s;
  short int s_steps = 0;
  while (true) {
    if (s_new >= 0) break;
    else { s_new += 60; s_steps++; }
  }

  short int m_new = m - s_steps;
  short int m_steps = 0;
  while (true) {
    if (m_new >= 0) break;
    else { m_new += 60; m_steps++; }
  }

  short int h_new = h - m_steps;
  while (true) {
    if (h_new >= 0) break;
    else h_new += 60;
  }

  return Czas{ 
    (unsigned short int)h_new, 
    (unsigned short int)m_new, 
    (unsigned short int)s_new 
  };
}

bool Czas::operator< (const Czas& other) const {
  unsigned short int lh, lm, ls, rh, rm, rs;
  lh = this->getH();  rh = other.getH();
  lm = this->getM();  rm = other.getM();
  ls = this->getS();  rs = other.getS();

  if (lh < rh) return true;
  else if (lh > rh) return false;
  else {
    if (lm < rm) return true;
    else if (lm > rm) return false;
    else {
      if (ls < rs) return true;
      else return false;
    }
  }
}

bool Czas::operator> (const Czas& other) const {
  unsigned short int lh, lm, ls, rh, rm, rs;
  lh = this->getH();  rh = other.getH();
  lm = this->getM();  rm = other.getM();
  ls = this->getS();  rs = other.getS();

  if (lh > rh) return true;
  else if (lh < rh) return false;
  else {
    if (lm > rm) return true;
    else if (lm < rm) return false;
    else {
      if (ls > rs) return true;
      else return false;
    }
  }
}

bool Czas::operator== (const Czas& other) const {
  unsigned short int lh, lm, ls, rh, rm, rs;
  lh = this->getH();  rh = other.getH();
  lm = this->getM();  rm = other.getM();
  ls = this->getS();  rs = other.getS();

  bool  hbool = lh == rh,
        mbool = lm == rm,
        sbool = ls == rs;

  if (hbool && mbool & sbool) return true;
  else return false;
}

bool Czas::operator!= (const Czas& other) const {
  unsigned short int lh, lm, ls, rh, rm, rs;
  lh = this->getH();  rh = other.getH();
  lm = this->getM();  rm = other.getM();
  ls = this->getS();  rs = other.getS();

  bool  hbool = lh != rh,
        mbool = lm != rm,
        sbool = ls != rs;

  if (hbool || mbool || sbool) return true;
  else return false;
}


uint64_t Czas::count_seconds() const {
  return sek + min * 60 + godz * 3600;
}

uint64_t Czas::count_minutes() const {
  return sek / 60 + min + godz * 60;
}

Czas Czas::time_to_midnight() const {
  unsigned short int h_new, m_new, s_new, h, m, s;
  h_new = 0;  m_new = 0;  s_new = 0;
  h = getH(); m = getM(); s = getS();

  h_new = 24 - h - (m > 0 ? 1 : 0);
  m_new = 60 - m - (s > 0 ? 1 : 0);
  s_new = 60 - s;

  return Czas{ h_new, m_new, s_new };
}


int main() {
  auto t = Czas{23, 59, 59};
  std::cout << "Pory dnia!" << std::endl;
  std::cout << "|- Noc =     [0;6)" << std::endl;
  std::cout << "|- Rano =    [6;12)" << std::endl;
  std::cout << "|- Dzien =   [12;18)" << std::endl;
  std::cout << "\\- Wieczor = [18;24)" << std::endl;
  std::cout << "==================================" << std::endl << std::endl;


  std::cout << "Startowa godzina " << t.to_string() << std::endl;
  std::cout << "Pora dnia: " << t.time_of_day() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  t.next_minute();
  std::cout << "Minela minuta.  Godzina " << t.to_string() << std::endl;
  std::cout << "Pora dnia: " << t.time_of_day() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  t.next_second();
  std::cout << "Minela sekunda. Godzina " << t.to_string() << std::endl;
  std::cout << "Pora dnia: " << t.time_of_day() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  t.next_hour();
  std::cout << "Minela godzina. Godzina " << t.to_string() << std::endl;
  std::cout << "Pora dnia: " << t.time_of_day() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  t.next_hour(); t.next_hour(); t.next_hour(); t.next_hour(); t.next_hour();
  std::cout << "Minelo 5 godzin. Godzina " << t.to_string() << std::endl;
  std::cout << "Pora dnia: " << t.time_of_day() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  t.next_hour(); t.next_hour(); t.next_hour(); t.next_hour(); t.next_hour();
  t.next_hour(); t.next_hour(); t.next_hour(); t.next_hour(); t.next_hour();
  std::cout << "Minelo 10 godzin. Godzina " << t.to_string() << std::endl;
  std::cout << "Pora dnia: " << t.time_of_day() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;


  auto t1 = Czas{ 12, 34, 50 };
  auto t2 = Czas{ 1, 6, 10 };
  auto t3 = Czas{ 1, 34, 52 };
  auto t4 = Czas{ 1, 34, 52 };

  std::cout << "Arytmetyka na godzinach!" << std::endl;
  std::cout << "Godzina T1: " << t1.to_string() << std::endl;
  std::cout << "Godzina T2: " << t2.to_string() << std::endl;
  std::cout << "Godzina T3: " << t3.to_string() << std::endl;
  std::cout << "Godzina T4: " << t4.to_string() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  std::cout << "T1 + T2 = " << (t1 + t2).to_string() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  std::cout << "T1 - T3 = " << (t1 - t3).to_string() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  std::cout << "T2 < T1 = " << ((t2 < t1) ? "true" : "false") << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  std::cout << "T2 > T3 = " << ((t2 > t3) ? "true" : "false") << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  std::cout << "T3 == T4 = " << ((t3 == t4) ? "true" : "false") << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  std::cout << "T3 != T2 = " << ((t3 != t2) ? "true" : "false") << std::endl;
  std::cout << "==================================" << std::endl << std::endl;


  std::cout << "Pólnoc!" << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  std::cout << "Sekund w T1: " << std::to_string(t1.count_seconds()) << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  std::cout << "Minut w T1: " << std::to_string(t1.count_minutes()) << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  std::cout << "Czas w T1 do polnocy: " << t1.time_to_midnight().to_string() << std::endl;
  std::cout << "==================================" << std::endl << std::endl;


  return 0;
}