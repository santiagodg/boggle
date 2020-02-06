#ifndef BOGGLE_H
#define BOGGLE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#include "Board.h"

class Boggle {
	public:
		Boggle();

    void readBoard();
    void readDictionary(const int &numWords);
		int score();

	private:
		Board board;
		vector<string> dict;
		map<int, int> reward;

		bool checkWord(string word, int ys, int ye, int xs, int xe);

};

Boggle::Boggle() : board() {
	reward[3] = 1;
	reward[4] = 1;
	reward[5] = 2;
	reward[6] = 3;
	reward[7] = 5;
	reward[8] = 11;
}

void Boggle::readBoard() {
	board.readBoard();
}

void Boggle::readDictionary(const int &numWords) {
	string word;
	for (int i = 0; i < numWords; i++) {
		cin >> word;
		dict.push_back(word);
	}
}

int Boggle::score() {
	int score = 0;
	for (int wordIndex = 0; wordIndex < dict.size(); wordIndex++) {
		string word = dict[wordIndex];
		board.unVisitAll();
		if (board.isOnBoard(word)) {
			if (word.length() < 8) {
				score += reward[word.length()];
			} else {
				score += reward[8];
			}
		} else {
		}
	}
	return score;
}

#endif
