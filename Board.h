#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include "Dice.h"

class Board {
  public:
    /**
      * Constructs default 4x4 board with default Dice.
      */
    Board();

    /**
     * Reads and updates board from standard input.
     *
     * EXAMPLE:
     * TNXO
     * AAEI
     * IOSR
     * BFRH
     */
    void readBoard();

    /**
     * Returns true if and only if the word is on the board. Consecutive
     * letters must be adjacent horizontally, vertically or diagonally and
     * not visited.
     */
    bool isOnBoard(string word);

    void unVisitAll();

  private:
    vector<vector<Dice> > board;
    int horizontalSize;
    int verticalSize;

    bool isOnBoard(string word, int ys, int ye, int xs, int xe);
};

Board::Board() : horizontalSize(4), verticalSize(4) {
  vector<Dice> row;
  for (int rowIndex = 0; rowIndex < 4; rowIndex++) {
    row.clear();
    for (int colIndex = 0; colIndex < 4; colIndex++) {
      row.push_back(Dice());
    }
    board.push_back(row);
  }
}

void Board::readBoard() {
  char input;
  for (int rowIndex = 0; rowIndex < verticalSize; rowIndex++) {
    for (int colIndex = 0; colIndex < horizontalSize; colIndex++) {
      board[rowIndex][colIndex].readLetter();
    }
  }
}

bool Board::isOnBoard(string word, int ys, int ye, int xs, int xe) {
  char letter;
  if (word.length() == 0) return true;
  for (int y = ys; y <= ye; y++) {
    for (int x = xs; x <= xe; x++) {
      letter = word[0];
      if (board[y][x].getLetter() == letter && !board[y][x].isVisited()) {
        board[y][x].visit();
        if (y == 0) {
          if (x == 0) {
            if (isOnBoard(word.substr(1, word.length() - 1), 0, 1, 0, 1)) {
              return true;
            } else {
              board[y][x].unVisit();
            }
          } else if (0 < x && x < horizontalSize - 1) {
            if (isOnBoard(word.substr(1, word.length() - 1), 0, 1, x - 1, x + 1)) {
              return true;
            } else {
              board[y][x].unVisit();
            }
          } else if (x == horizontalSize - 1) {
            if (isOnBoard(word.substr(1, word.length() - 1), 0, 1, horizontalSize - 2, horizontalSize - 1)) {
              return true;
            } else {
              board[y][x].unVisit();
            }
          }
        } else if (0 < y && y < verticalSize - 1) {
          if (x == 0) {
            if (isOnBoard(word.substr(1, word.length() - 1), y - 1, y + 1, 0, 1)) {
              return true;
            } else {
              board[y][x].unVisit();
            }
          } else if (0 < x && x < horizontalSize - 1) {
            if (isOnBoard(word.substr(1, word.length() - 1), y - 1, y + 1, x - 1, x + 1)) {
              return true;
            } else {
              board[y][x].unVisit();
            }
          } else if (x == horizontalSize - 1) {
            if (isOnBoard(word.substr(1, word.length() - 1), y - 1, y + 1, horizontalSize - 2, horizontalSize - 1)) {
              return true;
            } else {
              board[y][x].unVisit();
            }
          }
        } else if (y == verticalSize - 1) {
          if (x == 0) {
            if (isOnBoard(word.substr(1, word.length() - 1), verticalSize - 2, verticalSize - 1, 0, 1)) {
              return true;
            } else {
              board[y][x].unVisit();
            }
          } else if (0 < x && x < horizontalSize - 1) {
            if (isOnBoard(word.substr(1, word.length() - 1), verticalSize - 2, verticalSize - 1, x - 1, x + 1)) {
              return true;
            } else {
              board[y][x].unVisit();
            }
          } else if (x == horizontalSize - 1) {
            if (isOnBoard(word.substr(1, word.length() - 1), verticalSize - 2, verticalSize - 1, horizontalSize - 2, horizontalSize - 1)) {
              return true;
            } else {
              board[y][x].unVisit();
            }
          }
        }
      }
    }
  }
  return false;
}

bool Board::isOnBoard(string word) {
  return isOnBoard(word, 0, horizontalSize - 1, 0, verticalSize - 1);
}

void Board::unVisitAll() {
  for (int rowIndex = 0; rowIndex < verticalSize; rowIndex++) {
    for (int colIndex = 0; colIndex < horizontalSize; colIndex++) {
      board[rowIndex][colIndex].unVisit();
    }
  }
}

#endif
