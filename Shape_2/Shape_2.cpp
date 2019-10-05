// Name: Yiming Bi
// This is in class assignment 2 programe.

#include<iostream>
using namespace std;

int main() {

	// ask input for shape 2 and check if it is odd
	int shape_2_max_space;
	while (true) {
		cout << "Enter the maximun space of shape 2, please enter an odd number: \n";
		cin >> shape_2_max_space;
		if (shape_2_max_space % 2 == 1) {
			cout << "Your input " << shape_2_max_space << " is odd, shape 2 will be printed below. \n \n";
			break;
		}
		else {
			cout << "Your input " << shape_2_max_space << " is even, please enter again. \n \n";
		}
	}

	// print shape 2 in matrix form
	// every time when coordinate i and j satisfy certain condition, print "*"
	for (int i = 0; i < shape_2_max_space + 2; i++) {
		for (int j = 0; j <= shape_2_max_space + 1; j++) {
			if ((j == (shape_2_max_space + 2) / 2 + i) || (j == (shape_2_max_space + 2) / 2 - i) ||
				// these are basic conditions: from line 0, print "*" from line center to line ends
				// so the conditions are "+i" and "-i"
				(j == (shape_2_max_space + 2) / 2 + i - shape_2_max_space - 1) ||
				(j == (shape_2_max_space + 2) / 2 - i + shape_2_max_space + 1))
				// above two lines fold the down side of a big triangle back
				// keep move to line ends will lead the condition number go beyond j limitation
				// bring them back by adding or subtracting max space number, the +1 and -1 come from tests
			{
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;

	}

	return 0;
}