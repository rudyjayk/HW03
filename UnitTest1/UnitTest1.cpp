#include "pch.h"
#include "CppUnitTest.h"
#include "../HW03/readint.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCase1)
		{
			// create a string stream object with the desired input 
			istringstream ss("Hello\n0");

			// Replace the cin read buffer with the read buffer from the string stream 
			streambuf* orig_cin = cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test. 
			// cin will now read contents from your stringstream and not from the keyboard. 
			// We expect the correct value returned is 0, ignoring the Hello string. 
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			// Restore cin to the way it was before 
			cin.rdbuf(orig_cin);

			
		}
		TEST_METHOD(TestCase2)
		{
			// define a C++11 Lambda function to be called by your test 
			auto func = []() {
				// call with incorrect arguments (test case 2) 
				read_int("My prompt: ", 5, 1);
			};

			// We expect an invalid_argument exception to be thrown when we call func! 
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(TestCase3)
		{
			// Open a file stream to read the file zeroinput.txt (remember CS-172) 
			// Replace "UnitTester" with the name of your Native Unit Test project 
			ifstream ss("..\\UnitTest1\\zeroinput.txt");

			// Check if we opened the file stream successfully 
			if (ss.fail())
				throw int(-1); // throw an integer with value -1 

				// Replace the cin read buffer with the read buffer from the file stream 
			streambuf* orig_cin = cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test. 
			// cin will now read from your file and not from the keyboard. 
			// We expect the correct value returned is 0, ignoring the Hello string. 
			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			// Restore cin to the way it was before 
			cin.rdbuf(orig_cin);

			// Close the file stream 
			ss.close();
		}
		TEST_METHOD(TestCase4)
		{
			// define a C++11 Lambda function to be called by your test 
			auto func2 = []() {
				// call with incorrect arguments (test case 4) 
				read_int("My prompt: ", 0, 0);
			};

			// We expect an invalid_argument exception to be thrown when we call func! 
			Assert::ExpectException<std::invalid_argument>(func2);
		}
	};
}
