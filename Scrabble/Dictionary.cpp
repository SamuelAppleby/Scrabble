/*		 Created By Samuel Buzz Appleby
 *               03/02/2021
 *			Dictionary Implementation			 */
#include "Dictionary.h"
#include <set>
Dictionary::Dictionary(ifstream& file) {
	numWords = 0;
	validWords = nullptr;

	string line;
	int pos = 0;
	while (getline(file, line)) {
		if (pos == 0) {
			numWords = (atoi(line.c_str()));
			validWords = new string[numWords];
			++pos;
		}
		else {
			transform(line.begin(), line.end(), line.begin(), [](unsigned char c) { return toupper(c); });
			validWords[pos - 1] = line;
			++pos;
		}
	}
	//sort(validWords, validWords + numWords);		// If we need to sort the dictionary
}

Dictionary::~Dictionary() {
	delete[] validWords;
	validWords = nullptr;
}

