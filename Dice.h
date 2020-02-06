#ifndef DICE_H
#define DICE_H

#include <iostream>
using namespace std;

class Dice {
  public:
    Dice() : letter(), visitStatus(false) {}
    // Dice(char input) : letter(input), visited(false) {}

    /**
     * Reads letter as a character from standard input and updates it.
     *
     */
    void readLetter();

    /**
     * Marks dice as visited.
     */
    void visit();

    /**
     * Marks dice as unvisited.
     */
    void unVisit();

    bool isVisited();
    char getLetter();

  private:
    char letter;
    bool visitStatus;
};

bool Dice::isVisited() {
  return visitStatus;
}

char Dice::getLetter() {
  return letter;
}

void Dice::readLetter() {
  cin >> letter;
}

void Dice::visit() {
  visitStatus = true;
}

void Dice::unVisit() {
  visitStatus = false;
}

#endif
