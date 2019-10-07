// Name: Yiming Bi
// 503 In class assignment 3

#include<iostream>
#include<iomanip>

using namespace std;

void print_array(const int[], int);
int poll_winner(const int[], int);

int main() {

	// initialization
	const int poll_size = 20;
	int poll[poll_size];
	int input_temp = 0;
	int input_counter = 0;
	int user_choice = 0;
	int winner = 0;

	// ask input and comfirm with users
	cout << "You are using this program for the result of " << poll_size << " polls to 5 candidates. \n";
	cout << "Please enter integer 0 to 4 to represent each candidate for every single poll result, one at a time by using enter key. \n";
	
	// ask input of 20 array elements one by one
	// fits the real life better I believe
	while(true) {
		cout << "Your " << input_counter + 1 << " poll result is: \n";
		cin >> input_temp;
		if ((input_temp <= 4) && (input_temp >= 0)) {	
			// check if the input fits interval [0,4]
			poll[input_counter] = input_temp;
			input_counter += 1;
			if (input_counter >= poll_size) {	
				// after fill 20 elements in array, comfirm with user
				cout << "You already entered all " << poll_size << " results, they are:";
				print_array(poll, poll_size);
				cout << "\nTo re-enter, enter 1; otherwise enter any key: ";
				cin >> user_choice;
				if (user_choice == 1) {
					input_counter = 0;
					continue;
				}
				break;
			}
			continue;
		}
		cout << "Your input could not represent any candidate, input again please. \n";
	}

	// find mode and the result of poll
	winner = poll_winner(poll, poll_size);

	if (winner == 0) {
		cout << "There is no winner!\n";
		return 0;
	}

	// give output
	cout << "Winner is the candidate represented by number: " << winner << " ! \n";

	return 0;
}

// print the array, 5 elements in one line
void print_array(const int a[], int s) {
	for (int i = 0; i < s; i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << setw(3) << a[i];
	}
}

// find mode by using another array to store the frequency
int poll_winner(const int a[], int s) {
	int winner = 0;
	int largest = 0;
	int poll_counter[5] = { 0, 0, 0, 0, 0 };

	for (int i = 0; i < s; i++) {
		poll_counter[a[i]] += 1;
	}

	// mode is the index with maximun frequency
	for (int rate = 0; rate < 5; rate++) {
		if (poll_counter[rate] > largest) {
			largest = poll_counter[rate];
			winner = rate;
		}
	}

	// need to check if there are more than one winner... accroding to the insrtuction
	for (int rate = 0; rate < 5; rate++) {
		if (poll_counter[rate] == largest) {
			winner = 0;
		}
	}

	return winner;
}
