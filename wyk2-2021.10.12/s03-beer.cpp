#include <iostream>

int main(int argc, char* argv[]) {
  int beers = argc >= 2 ? atoi(argv[1]) : 99;

  do {
    printf("%d bottles of beer on the wall, %d bottles of beer.\n", beers, beers);
    printf("Take one down, pass it around, %d bottles of beer on the wall...\n\n", --beers);
    
    if (beers <= 0) {
      printf("No more bottles of beer on the wall, no more bottles of beer.\n");
      printf("Go to the store and buy some more, 99 bottles of beer on the wall...\n");
    }
  } while (beers > 0);

  return 0;
}