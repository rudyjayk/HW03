#include <iostream> 
#include <stdexcept> 
#include "readint.h" 
using namespace std;

int main() {
	
	//Added an exception where if high and low was to have a bad input value.
	cin.exceptions(ios_base::failbit);
	int low = NULL, high; //Set low == NULL so a while loop could be created below.
	while (low == NULL){
		try {
			cout << "Enter the range of values to read.\n";
			cout << "high: ";
			cin >> high;
			cout << "low: ";
			cin >> low;
		}
		catch (ios_base::failure& ex) { //For when an invlaid input value is inputted for low or high
			cout << "Bad input value! Try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} 

	try
	{
		int number = read_int("Please enter a number within the range: ", low, high); //Calling of read_int
		cout << "You entered " << number << endl; //prints the number you chose
	}
	catch (invalid_argument& e) { //For invalid argument when high < low and an empty set would be formed
		cerr << "Exception: You supplied an invalid argument for read_int!\n";
	}
	
	
}