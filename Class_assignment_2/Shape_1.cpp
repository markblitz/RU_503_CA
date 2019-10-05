// Name: Yiming Bi
// This is in class assignment 2, shape 1 programe.

#include<iostream>
using namespace std;

int main() {

	// ask input
	cout << "How many lines do you want in this shape 1? \n";
	int shape_1_line_number;
	cin >> shape_1_line_number;
	cout << "A " << shape_1_line_number << " line(s) shape will be printed below. \n \n";

	// use loops to print shape 1
	// the inner loop prints certain number of "*"
	// the outer loop controls the line switch
	for (int i = 1; i <= shape_1_line_number; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
