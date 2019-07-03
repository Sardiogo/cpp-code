// calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
// VS_2019
// Run program: Ctrl + F5 Start Without Debugging menu
// Debug program: F5 
// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include "calculator_math.h"
// The #include statements allow you to reference code located in other files. 
// Sometimes, you may see a filename surrounded by angle brackets (<>); other times, it's surrounded by quotes (" "). 
// In general, angle brackets are used when referencing the C++ Standard Library, while quotes are used for other files.*/

using namespace std;
// The using namespace std; line tells the compiler to expect stuff from the C++ Standard Library to be used in this file. 
// Without this line, each keyword from the library would have to be preceded with a std::, to denote its scope. 
// For instance, without that line, each reference to cout would have to be written as std::cout. 
// The using statement is added to make the code look more clean.

int main(void)
{
	double x = 0.0;
	double y = 0.0;
	double result = 0.0;
	char oper = '+';

	cout << "Calculator Console Application \n\n";
	cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b" << endl;

	// The cout keyword is used to print to standard output in C++. 
	// The << operator tells the compiler to send whatever is to the right of it to the standard output.
	// The endl keyword is like the Enter key; it ends the line and moves the cursor to the next line. 
	// It is a better practice to put a \n inside the string (contained by "") to do the same thing, as endl always flushes 
	// the buffer and can hurt the performance of the program, but since this is a very small app, endl is used instead for better readability

	calculator_math c;
	// declares an object named 'c' as an instance of the calculator_math class. 
	// The class itself is just a blueprint for how calculators work; the object is the specific calculator that does the math.

	while (true)
	{
		cin >> x >> oper >> y;
		// The cin keyword is used to accept input from the user. 
		// This input stream is smart enough to process a line of text entered in the console window and place it inside each of the variables listed, in order, 
		// assuming the user input matches the required specification. You can modify this line to accept different types of input, for instance, more than two numbers, 
		// though the Calculate() function would also need to be updated to handle this.

		if (oper == '/' && y == 0)
		{
			cout << "Division by 0 exception" << endl;
			continue;
		}
		else
		{
			result = c.Calculate(x, oper, y);
			// The c.Calculate(x, oper, y); expression calls the Calculate function defined earlier, and supplies the entered input values. 
			// The function then returns a number that gets stored in resul
		}

		cout << "Result is: " << result << endl;
		// Finally, result is printed to the console, so the user sees the result of the calculation.
	}

	return 0;
}

