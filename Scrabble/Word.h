/*		 Created By Samuel Buzz Appleby
 *               03/02/2021
 *			   Lock Definition			 */
#pragma once
#include "Dictionary.h" 
#include <set>
using namespace std;
class Word {
public:
	Word(string name, Dictionary& d);

	set<string> GenerateAndTestCombinations();
	void TestCombination(string name);
	int BinarySearch(string arr[], string x, int n);


private:
	string word;
	set<string> foundWords;
	Dictionary* dictionary;
	int bestLeft;
};

