#include "readint.h" 
#include <stdexcept> 
#include <iostream>
using namespace std;

int read_int(const string& prompt, int low, int high)
{
	if (high < low) { //If an empty set is created it throws an invalid argument back to main

		throw invalid_argument("");
	}

	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true) {
		try {
			cout << prompt;
			cin >> num;
			if (num >= high || num <= low) { //Second throw inside the read_int function
											 //This throw is used to identify if the user inputs a number not in the range
				throw range_error("The number you have entered is not in range! Try again!");
			}
			return num;
		}
		catch (ios_base::failure& ex) { //Another exception to catch if a bad input value is inputted
			cout << "Bad input value! Try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (range_error& re) { //From the throw above
			cout << re.what() << endl;
		}
		
	}
}