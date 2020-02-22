#include <iostream>
using namespace std;

long long int factorial(long long int num);
double sumover(unsigned int n);
void tower(const int& disk, const int& fromPole, const int& toPole);

int main() {
	int option = 0;

	while (option != 4) {
		cout << "*******************************************************" << endl;
		cout << "** Welcome to the main menu, choose an option below! **" << endl;
		cout << "*******************************************************" << endl;

		cout << "*******************************************************" << endl;
		cout << "** 1. Sum                                            **" << endl;
		cout << "** 2. Factorial                                      **" << endl;
		cout << "** 3. Tower                                          **" << endl;
		cout << "** 4. Exit                                           **" << endl;
		cout << "*******************************************************" << endl;

		cin >> option;

		//ASK FOR INPUT AS LONG AS USER INPUTS INVALID OPTION
		while (option > 4 || option < 1) {
			cout << "Invalid input, try again: 1, 2, 3, or 4" << endl;
			cin >> option;
		}

		//USER SELECTS 1
		if (option == 1) {
			int n;
			cout << "Welcome to the sumover function, This function returns the sum of the reciprocals of the first n positive integers" << endl;
			cout << "Please enter the integer you want to sumover: " << endl;
			cin >> n;
			cout << "The sumover of " << n << " is " << sumover(n) << endl;
		}
		//USER SELECTS 2
		else if (option == 2) {
			int num;
			cout << "Welcome to the factorial function, This function returns the factorial of integer n" << endl;
			cout << "Please enter the integer you want to find the factorial of: " << endl;
			cin >> num;
			cout << "The factorial of " << num << " is " << factorial(num) << endl;
		}
		//USER SELECTS 3
		else if (option == 3) {
			int n, fPole, tPole;
			cout << "Welcome to the Tower of Hanoi function, This function returns the steps taken to complete the puzzle" << endl;
			cout << "Number of disks: ";
			cin >> n;
			cout << "Move these disk(s) from which pole to which pole?\n";
			cout << "From: ";
			cin >> fPole;
			cout << "To: ";
			cin >> tPole;
			tower(n, fPole, tPole);
		}
	}

	//USER SELECTS 4
	cout << "You have successfully exited the program!" << endl;

	return 0;
}

//FACTORIAL FUNCTION
long long int factorial(long long int num) {
	if (num == 1) return 1;

	return num * factorial(num - 1);
}

//SUMOVER FUNCTION
double sumover(unsigned int n) {
	if (n == 0)
		return 0.0;
	if (n == 1)
		return 1.0;

	return ((double)1 / n + sumover(n - 1));
}

//TOWER OF HANOI FUNCTION
void tower(const int& disk, const int& fromPole, const int& toPole) {
	if (disk == 1)
		cout << "Move from " << fromPole << " to " << toPole << endl;
	else {
		int unusedPole = 6 - fromPole - toPole;
		tower(disk - 1, fromPole, unusedPole);
		cout << "Move from " << fromPole << " to " << toPole << endl;
		tower(disk - 1, unusedPole, toPole);
	}
}