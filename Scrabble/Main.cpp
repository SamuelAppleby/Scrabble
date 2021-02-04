/*		 Created By Samuel Buzz Appleby
 *               03/02/2021
 *			        Main			    */
#include <iostream>
#include <fstream>
#include "Dictionary.h"
#include "Word.h"
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

    cout << "Creating Word..." << endl;
    Word word("SAMUEL", dictionary);

    cout << "Finding Words..." << endl;
    set<string> foundWords = word.GenerateAndTestCombinations();
    OutputWords(foundWords);
    return 0;
}