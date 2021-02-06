/*		 Created By Samuel Buzz Appleby
 *               06/02/2021
 *			  Lock Implementation			 */
#include "Word.h"
Word::Word(string name, Dictionary& d) {
	dictionary = &d;
	word = name;
	string line;
	int pos = 0;
}

/* Given our number of wheels(N) and characters per wheel (M), we test every possible combination, M ^ N */
set<string> Word::GenerateAndTestCombinations(bool max) {
	maxOnly = max;
	sort(word.begin(), word.end());
	do {
		TestCombination(word);
	} while (next_permutation(word.begin(), word.end()));
	return foundWords;
}

/* We can perform a binary search on our ordered containers */
int Word::BinarySearch(string arr[], string x, int n) {
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (x == (arr[m])) {
			return m;
		}
		else if (x > (arr[m]))
			l = m + 1;
		else
			r = m - 1;
	}
	return 0;
}

/* Given our word configuration, we see what words can be made */
void Word::TestCombination(string name) {
	if (maxOnly) {
		if (BinarySearch(dictionary->GetValidWords(), name, dictionary->GetNumWords()))
			foundWords.insert(name);
	}
	else {
		string substr;
		for (int i = 0; i < name.length() - 1; ++i) {
			substr.clear();
			/* Keep going along the current combination to see if we can extend the word */
			while (i + substr.size() < name.length()) {
				if (substr.size() == 0)		// First round
					substr += (name[i]);
				substr += (name[i + substr.size()]);
				if (BinarySearch(dictionary->GetValidWords(), substr, dictionary->GetNumWords()))
					foundWords.insert(substr);
			}
		}
	}
}