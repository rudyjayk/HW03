#ifndef READINT_H_
#define READINT_H_ 
#include <string> 


//This function takes in a prompt and two integers
//The prompt's purpose is to prompt the user a question basically asking the user to enter a number
//The two integers are to create a range of numbers that are not inclusive
//EX: 1,5		Range: 2,3,4
int read_int(const std::string& prompt, int low, int high);

#endif 