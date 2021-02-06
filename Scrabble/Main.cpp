/*		 Created By Samuel Buzz Appleby
 *               06/02/2021
 *			        Main			    */
#include <iostream>
#include <fstream>
#include "Dictionary.h"
#include "Word.h"
#include <regex>
using namespace std;

/* Outputs all found words to console and output.txt */
void OutputWords(set<string> foundWords) {
    ofstream outFile;
    outFile.open("output.txt");
    if (!outFile) {
        cout << "Cannot Create File";
        return;
    }
    for (auto& w : foundWords) {
        cout << w << endl;
        outFile << w << "\n";
    }
    cout << "Words Found:" << foundWords.size() << endl;
    outFile << "Words Found:" << foundWords.size() << "\n";
    outFile.close();
}

/* Takes in a file name and will return a file stream */
ifstream LoadFile(string fileName) {
    ifstream infile(fileName);
    if (!infile) {
        cout << fileName << " Does Not Exist";
    }
    return infile;
}

int main() {
    cout << "Loading Files..." << endl;
    ifstream dictionaryStream = LoadFile("dictionary.txt");
    if (!dictionaryStream)
        return -1;

    cout << "Creating Dictionary..." << endl;
    Dictionary dictionary(dictionaryStream);

    cout << "TYPE '0' TO EXIT AT ANY TIME" << endl;
    string input;
    while (input != "0") {
        input.clear();
        cout << "Type Your Scrabble Tiles: ";
        cin >> input;
        while (!regex_match(input, std::regex("^[A-Za-z]+$")) && !regex_match(input, std::regex("^[0]$"))) {
            cout << "Invalid Word, Try Again: ";
            cin >> input;
        }
        if (input == "0")
            break;

        cout << "Creating Word..." << endl;
        transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return toupper(c); });
        Word word(input, dictionary);

        input.clear();
        cout << "Would you like all words (1) or max length only (2)?: ";
        cin >> input;
        while (!regex_match(input, std::regex("^[12]$")) && !regex_match(input, std::regex("^[0]$"))) {
            cout << "Invalid Input, would you like all words (1) or max length only (2)?: ";
            cin >> input;
        }
        if (input == "0")
            break;

        bool maxOnly = input == "2" ? true : false;
        cout << "Finding Words..." << endl;
        OutputWords(word.GenerateAndTestCombinations(maxOnly));
    }
    return 0;
}