#ifndef BOGGLE_H
#define BOGGLE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Boggle {
	private:
		char board[4][4];
		vector<string> dict;
		map<int, int> reward;
		bool visited[4][4];

		bool checkWord(string word, int ys, int ye, int xs, int xe);

	public:
		Boggle();

    void readBoard();
    void readDictionary(const int &numWords);
		int score();

		void printBoard();
		void printDictionary();
};

Boggle::Boggle() {
	reward[3] = 1;
	reward[4] = 1;
	reward[5] = 2;
	reward[6] = 3;
	reward[7] = 5;
	reward[8] = 11;
}

void Boggle::readBoard() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> board[i][j];
		}
	}
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
	for (int word = 0; word < dict.size(); word++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				visited[i][j] = false;
			}
		}

		// cout << endl;
		// cout << "CHECKING " << dict[word] << "..." << endl;

		if (checkWord(dict[word], 0, 3, 0, 3)) {
			// cout << "FOUND IT" << endl;
			if (dict[word].length() < 8) {
				// cout << "found word: " << dict[word] << ", adding " << reward[dict[word].length()] << " point(s) to the score." << endl;
				score += reward[dict[word].length()];
			} else {
				// cout << "found word: " << dict[word] << ", adding " << reward[8] << " points to the score." << endl;
				score += reward[8];
			}
		} else {
			// cout << "DID NOT FIND IT" << endl;
		}
		// cout << endl;
	}
	return score;
}

bool Boggle::checkWord(string word, int ys, int ye, int xs, int xe) {
	if (word.length() == 0) return true;
	for (int y = ys; y <= ye; y++) {
		for (int x = xs; x <= xe; x++) {
			if (board[y][x] == word[0] && !visited[y][x]) {
				visited[y][x] = true;
				// cout << "found " << word[0] << " from " << word << endl;
				switch (y) {
					case 0:
						switch (x) {
							case 0:
								if (checkWord(word.substr(1, word.length() - 1), 0, 1, 0, 1)) {
									return true;
								} else {
									visited[y][x] = false;
									// cout << "backtracking..." << endl;
								}
								break;
							case 1:
							case 2:
								if (checkWord(word.substr(1, word.length() - 1), 0, 1, x - 1, x + 1)) {
									return true;
								} else {
									visited[y][x] = false;
									//cout << "backtracking..." << endl;
								}
								break;
							case 3:
								if (checkWord(word.substr(1, word.length() - 1), 0, 1, 2, 3)) {
									return true;
								} else {
									visited[y][x] = false;
									// cout << "backtracking..." << endl;
								}
								break;
						}
						break;
					case 1:
					case 2:
						switch (x) {
							case 0:
								if (checkWord(word.substr(1, word.length() - 1), y - 1, y + 1, 0, 1)) {
									return true;
								} else {
									visited[y][x] = false;
									// cout << "backtracking..." << endl;
								}
								break;
							case 1:
							case 2:
								if (checkWord(word.substr(1, word.length() - 1), y - 1, y + 1, x - 1, x + 1)) {
									return true;
								} else {
									visited[y][x] = false;
									// cout << "backtracking..." << endl;
								}
								break;
							case 3:
								if (checkWord(word.substr(1, word.length() - 1), y - 1, y + 1, 2, 3)) {
									return true;
								} else {
									visited[y][x] = false;
									// cout << "backtracking..." << endl;
								}
								break;
						}
						break;
					case 3:
						switch (x) {
							case 0:
								if (checkWord(word.substr(1, word.length() - 1), 2, 3, 0, 1)) {
									return true;
								} else {
									visited[y][x] = false;
									// cout << "backtracking..." << endl;
								}
								break;
							case 1:
							case 2:
								if (checkWord(word.substr(1, word.length() - 1), 2, 3, x - 1, x + 1)) {
									return true;
								} else {
									visited[y][x] = false;
									// cout << "backtracking..." << endl;
								}
								break;
							case 3:
								return checkWord(word.substr(1, word.length() - 1), 2, 3, 2, 3);
								break;
						}
						break;
				}
			} else if (x == xe && y == ye) {
				// cout << "did not find " << word[0] << " from " << word << endl;
			}
		}
	}
	return false;
}

void Boggle::printBoard() {
	cout << endl;
	cout << "PRINTING BOARD" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "FINISHED PRINTING BOARD" << endl;
	cout << endl;
}

void Boggle::printDictionary() {
	cout << endl;
	cout << "PRINTING DICTIONARY" << endl;
	for (int i = 0; i < dict.size(); i++) {
		cout << dict[i] << endl;
	}
	cout << "FINISHED PRINTING DICTIONARY" << endl;
	cout << endl;
}

#endif
