// Demonstrating C++ Standard Library class template vector.
#include "vector_op.h" // include definition of functions.

int main()
{
	vector< int > integers1(7); // 7-element vector< int > called integers1
	vector< int > integers2(10); // 10-element vector< int >
	// Create two vector objects that store values of type int.
	// Note that vectors can be defined to store any data type, by replacing int in vector<int> with the appropriate data type.
	// This notation specifies the type stored in the vector

	// print integers1 size and contents
	cout << "Size of vector integers1 is " << integers1.size() << "\nvector after initialization:" << endl;
	//vector member function size to obtain the size (i.e., the number of elements) of integers1. To invoke a member function, you access it with the dot (.) operator. outputVector
	outputVector(integers1); // user-defined function

	// print integers2 size and contents
	cout << "\nSize of vector integers2 is " << integers2.size() << "\nvector after initialization:" << endl;
	outputVector(integers2); // user-defined function

	// input and print integers1 and integers2
	cout << "\nEnter 17 integers:" << endl;
	inputVector(integers1); // user-defined function
	inputVector(integers2); // user-defined function

	cout << "\nAfter input, the vectors contain:\n" << "integers1:" << endl;
	outputVector(integers1); // user-defined function
	cout << "integers2:" << endl;
	outputVector(integers2); // user-defined function

	// use inequality (!=) operator with vector objects
	cout << "\nEvaluating: integers1 != integers2" << endl;

	if (integers1 != integers2)
		cout << "integers1 and integers2 are not equal" << endl;

	// create vector integers3 using integers1 as an
	// initializer; print size and contents
	vector< int > integers3(integers1); // copy constructor - create a new vector object that is initialized with the contents of an existing vector.

	cout << "\nSize of vector integers3 is " << integers3.size() << "\nvector after initialization:" << endl;
	outputVector(integers3);

	// use overloaded assignment (=) operator
	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2; // assign integers2 to integers1

	cout << "integers1:" << endl;
	outputVector(integers1);
	cout << "integers2:" << endl;
	outputVector(integers2);

	// use equality (==) operator with vector objects
	cout << "\nEvaluating: integers1 == integers2" << endl;

	if (integers1 == integers2)
		cout << "integers1 and integers2 are equal" << endl;

	// use square brackets to create rvalue
	cout << "\nintegers1[5] is " << integers1[5];

	// use square brackets to create lvalue
	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[5] = 1000;
	cout << "integers1:" << endl;
	outputVector(integers1);

	// attempt to use out-of-range index
	// enables you to create fault-tolerant programs that can resolve (or handle) exceptions.
	// this allows a program to continue executing as if no problems were encountered.
	/* The try block contains the code that might throw an exception, and the catch block contains the code that handles the exception if one occurs. You can have many catch blocks to handle different types of exceptions that might be thrown in the corresponding try block. If the code in the try block executes successfully, catch block is ignored. Because bounds checking is performed at execution time, vector member function at generates an exception — specifically throws an out_of_range exception (from header <stdexcept>) to notify the program of this problem. At this point, the try block terminates immediately and the catch block begins executing — if you declared any variables in the try block, they’re now out of scope and are not accessible in the catch block.The catch block declares a type (out_of_range) and an exception parameter (ex) that it receives as a reference. The catch block can handle exceptions of the specified type. Inside the block, you use the parameter’s identifier to interact with a caught exception object. the exception object’s what member function gets the error message that is stored in the exception object and display it. Once the message is displayed in this example, the exception is considered handled and the program continues with the next statement after the catch block’s closing brace.
	*/
	try
	{
		cout << "\nAttempt to display integers1.at( 15 )" << endl;
		cout << integers1.at(15) << endl; // ERROR: out of range
	}
	catch (out_of_range& ex)
	{
		cout << "An exception occurred: " << ex.what() << endl;
	}
}

// output vector contents
void outputVector(const vector< int >& array)
{
	size_t i; // declare control variable
	for (i = 0; i < array.size(); ++i)
	{
		cout << setw(12) << array[i];
		// setw - Sets the field width (screen spaces) to be used on output operations.
		if ((i + 1) % 4 == 0) // 4 numbers per row of output
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
}

// input vector contents
void inputVector(vector< int >& array)
{
	for (size_t i = 0; i < array.size(); ++i)
		cin >> array[i];
}