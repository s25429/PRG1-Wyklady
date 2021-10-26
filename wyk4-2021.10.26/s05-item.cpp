#include <iostream>
#include "include/Item.h"

int main() {
  Creature ogre{"Shrek", 10};

  Sword sword{};
  Axe   axe{};
  Bow   bow{};

  Health_potion potion{};

  sword.use_on(ogre);
  std::cout << "Ogre's health after sword hit: " << ogre.zycie << std::endl;

  potion.use_on(ogre);
  std::cout << "Ogre's health after drinking potion: " << ogre.zycie << std::endl;

  bow.use_on(ogre);
  std::cout << "Ogre's health after bow hit: " << ogre.zycie << std::endl;

  potion.use_on(ogre);
  std::cout << "Ogre's health after drinking potion again: " << ogre.zycie << std::endl;

  axe.use_on(ogre);
  std::cout << "Ogre's health after axe hit: " << ogre.zycie << std::endl;

  potion.use_on(ogre);
  std::cout << "Ogre's health after drinking potion for the third time: " << ogre.zycie << std::endl;

  axe.use_on(ogre);
  std::cout << "Ogre's health after axe hit: " << ogre.zycie << std::endl;

  sword.use_on(ogre);
  std::cout << "Ogre's health after sword hit: " << ogre.zycie << std::endl;

  return 0;
}