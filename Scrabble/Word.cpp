/*		 Created By Samuel Buzz Appleby
 *               03/02/2021
 *			  Lock Implementation			 */
#include "Word.h"
Word::Word(string name, Dictionary& d) {
	bestLeft = 0;
	dictionary = &d;
	word = name;
	string line;
	int pos = 0;
}

/* Given our number of wheels(N) and characters per wheel (M), we test every possible combination, M ^ N */
set<string> Word::GenerateAndTestCombinations() {
	sort(word.begin(), word.end());
	do {
		TestCombination(word);
	} while (next_permutation(word.begin(), word.end()));
	return foundWords;
}

/* We can perform a binary search on our ordered containers */
int Word::BinarySearch(string arr[], string x, int n) {
	int l = bestLeft;
	int r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (x == (arr[m])) {
			bestLeft = m;		// If we find a match, the next possible string MUST be to the right
			return m;
		}
		else if (x > (arr[m]))
			l = m + 1;
		else
			r = m - 1;
	}
	bestLeft = 0;
	return 0;
}

/* Given our lock configuration, we see what words can be made */
void Word::TestCombination(string name) {
	if (BinarySearch(dictionary->GetValidWords(), name, dictionary->GetNumWords()))
		foundWords.insert(name);
}