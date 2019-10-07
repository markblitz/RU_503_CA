// Name: Yiming Bi
// This is the countBinStr method for 503 class assignment 4

#include<iostream>

using namespace std;

long countBinStr(const int& n);

long countBinStr(const int& n)
{
	// if there is only one bit, there will be two possible strings "0" and "1"
	if (n == 1) {
		return 2;
	}

	if (n == 0) {
		return 1;
	}
	// the new string will have one more possible situation for each "1" at the end of last round
	// each "0" and the end of last round will turn to "1" at the end in the new string
	// this result becomes Fibonacci sequence
	return countBinStr(n - 1) + countBinStr(n - 2);
}

int main() {

	cout << "Please enter the number of bits:\n";
	int number_of_bit;
	cin >> number_of_bit;
	cout << "There will be " << countBinStr(number_of_bit) << " possible strings for " << number_of_bit << " bits do not have two consecutive 0.\n";

	return 0;
}
