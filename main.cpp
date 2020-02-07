#include <iostream>
#include <string>
using namespace std;

#include "Boggle.h"

int main() {
  int numGames;
  cin >> numGames;

  for (int i = 0; i < numGames; i++) {
    Boggle boggle;
    // boggle.readBoard();
    // boggle.printBoard();

    int numWords;
    cin >> numWords;

    int score = boggle.score();
    cout << "Game " << (i + 1) << ": " << score << endl;
  }

  return 0;
}
