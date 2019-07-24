#include "calculator_math.h"

/*
The .h file declares the function prototype, which tells the compiler upfront what parameters it requires, and what return type to expect from it. 
The .cpp file has all the implementation details of the function.
*/

double calculator_math::Calculate(double x, char oper, double y)
{
	switch (oper)
	{
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		default:
			return 0.0;
	}
}
