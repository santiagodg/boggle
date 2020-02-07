#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Dictionary {
  public:
    Dictionary();
    int size();

    string operator[](int index);

    string randomWord();
    char randomLetter();

    void print();

  private:
    vector<string> dict;
    void readDictionary();

    // mt19937 gen;
};

Dictionary::Dictionary() {
  readDictionary();
  // gen.seed(time(NULL));
}

void Dictionary::readDictionary() {
  ifstream file;
  file.open("dict.txt");
  string word;
  while (file >> word) {
    dict.push_back(word);
  }
}

int Dictionary::size() {
  return dict.size();
}

string Dictionary::randomWord() {
  return dict[rand() % dict.size()];
}

char Dictionary::randomLetter() {
  string word = randomWord();
  // cout << endl;
  // cout << "RANDOMWORD RETURNED " << word << endl;

  int randomIndex = rand() % word.length();
  // cout << "RANDOMLETTER RETURNED: " << word[randomIndex] << endl;
  // cout << endl;
  return word[randomIndex];
}

void Dictionary::print() {
  for (string word : dict) {
    cout << word << endl;
  }
}

string Dictionary::operator[](int index) {
  return dict[index];
}

#endif
