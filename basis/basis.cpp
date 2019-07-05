#include <iostream> // allows program to perform input and output
#include "maximum.h" // include definition of function template maximum

using std::cout;
using std::cin;
using std::endl;
// Alternative: using namespace std;
// which enables a program to use all the names in any standard C++ header file (such as <iostream>) 

// C++ provides the unary scope resolution operator (::) to access a global variable when a local variable of the same name is in scope.
// A global variable can be accessed directly without the unary scope resolution operator if the name of the global variable is not the same as that of a local variable in scope.
int number = 7; // global variable named number

// Definition of inline function cube. 
// Definition of function appears before function is called, so a function prototype is not required.
// First line of function definition acts as the prototype.
inline double cube(const double side)
{
	return side * side * side; // calculate the cube of side
}

int squareByValue(int); // function prototype (value pass)
void squareByReference(int &); // function prototype (reference pass)

// function prototype that specifies default arguments
int boxVolume(int length = 1, int width = 1, int height = 1);
/*default argument, i.e., a default value to be passed to that parameter.
Default arguments must be the rightmost (trailing) arguments in a function’s parameter list.
When calling a function with two or more default arguments, if an omitted argument is not the
rightmost argument in the argument list, then all arguments to the right of that argument also must be omitted.*/

 /* function overloading - C++ enables several functions of the same name to be defined, 
	as long as these functions have different sets of parameters
	When an overloaded function is called, the C++ compiler selects
	the proper function by examining the number, typesand order of the arguments in the
	call.Function overloading is commonly used to create several functions of the same name
	that perform similar tasks, but on data of different types.For example, many functions in
	the math library are overloaded for different numeric data types */
// function square for int values - function overloading
int square(int x)
{
	cout << "square of integer " << x << " is ";
	return x * x;
}
// function square for double values - function overloading
double square(double y)
{
	cout << "square of double " << y << " is ";
	return y * y;
}

int main()
{
	double number = 10.5; // local variable named number
	// display values of local and global variables
	cout << "Local double value of number = " << number << "\nGlobal int value of number = " << ::number << endl;

	double sideValue; // stores value entered by user
	for (int i = 1; i <= 3; i++)
	{
		cout << "\nEnter the side length of your cube: ";
		cin >> sideValue; // read value from user
		// calculate cube of sideValue and display result
		cout << "Volume of cube with side " << sideValue << " is " << cube(sideValue);
	}

	int count = 3; 
	int &cRef = count; // cRef refers to (is an alias for) count
	cout << "\n\nx = " << count << endl << "cRef = " << cRef << endl;
	cRef = 7; // actually modifies count
	cout << "count = " << count << endl << "cRef = " << cRef << endl;

	/*The “styles” of the arguments in the calls to function squareByValue and function
	squareByReference are identical—both variables are simply mentioned by name
	in the function calls. Without checking the function prototypes or function definitions,
	it’s not possible to tell from the calls alone whether either function can modify its arguments.*/
	// demonstrate squareByValue
	int x = 4;
	cout << "\nx = " << x << " before squareByValue\n";
	cout << "Value returned by squareByValue: " << squareByValue(x) << endl;
	cout << "x = " << x << " after squareByValue\n";
	// demonstrate squareByReference
	int z = 4;
	cout << "z = " << z << " before squareByReference" << endl;
	//cout << "Value returned by squareByReference: " << squareByReference(z) << endl; Error
	squareByReference(z);
	cout << "z = " << z << " after squareByReference" << endl;

	// no arguments--use default values for all dimensions
	cout << "\nThe default box volume is: " << boxVolume();
	// specify length; default width and height
	cout << "\nThe volume of a box with length 10,\n"	<< "width 1 and height 1 is: " << boxVolume(10);
	// specify length and width; default height
	cout << "\nThe volume of a box with length 10,\n"	<< "width 5 and height 1 is: " << boxVolume(10, 5);
	// specify all arguments
	cout << "\nThe volume of a box with length 10,\n" << "width 5 and height 2 is: " << boxVolume(10, 5, 2) << endl << endl;

	cout << square(7); // calls int version
	cout << endl;
	cout << square(7.5); // calls double version
	cout << endl << endl;

	// use the maximum function template to determine the largest of three general values
	// demonstrate maximum with int values
	int int1, int2, int3;
	cout << "Input three integer values: ";
	cin >> int1 >> int2 >> int3;
	// invoke int version of maximum
	cout << "The maximum integer value is: " << maximum(int1, int2, int3);
	// demonstrate maximum with double values
	double double1, double2, double3;
	cout << "\n\nInput three double values: ";
	cin >> double1 >> double2 >> double3;
	// invoke double version of maximum
	cout << "The maximum double value is: " << maximum(double1, double2, double3);
	// demonstrate maximum with char values
	char char1, char2, char3;
	cout << "\n\nInput three characters: ";
	cin >> char1 >> char2 >> char3;
	// invoke char version of maximum
	cout << "The maximum character value is: " << maximum(char1, char2, char3) << endl;
	// Three functions are created as a result of each of the 3 calls to the maximum function template, expecting three int values, three double valuesand three char values, respectively.
}

// squareByValue multiplies number by itself, stores the
// result in number and returns the new value of number
int squareByValue(int number)
{
	return number *= number; // caller's argument not modified
}

// squareByReference multiplies numberRef by itself and stores the result
// in the variable to which numberRef refers in the caller
void squareByReference(int &numberRef)
{
	numberRef *= numberRef; // caller's argument modified
}

// function boxVolume calculates the volume of a box
int boxVolume(int length, int width, int height)
{
	return length * width * height;
}
