#include <string>

struct Creature {
  std::string nazwa;
  int zycie;

  Creature(std::string n, int h) : nazwa(n), zycie(h) {};
};

struct Item {
  virtual int strength() = 0;
  virtual void use_on(Creature &c) = 0;
};


struct Weapon : Item {
  void use_on(Creature &c) { c.zycie -= strength(); };
};

struct Sword : Weapon {
  int strength() { return 4; };
};

struct Axe : Weapon { 
  int strength() { return 5; };
};

struct Bow : Weapon {
  int strength() { return 2; };
};


struct Potion : Item {
  void use_on(Creature &c) { c.zycie += strength(); };
};

struct Health_potion : Potion {
  int do_uzytku = 2;
  int strength() { return (do_uzytku-- > 0 ? 5 : 0); };
};
