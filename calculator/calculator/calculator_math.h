#pragma once
/*
C++ code is organized into header (.h) files and source (.cpp) files. 
Several other file extensions are supported by various compilers, but these are the main ones to know about. 
Functions and variables are normally declared, that is, given a name and a type, in header files, and implemented, or given a definition, in source files. 
To access code defined in another file, you can use #include "filename.h", where 'filename.h' is the name of the file that declares the variables or functions you want to use.
*/

class calculator_math
{
	public:
		double Calculate(double x, char oper, double y);
		// The line you added declares a new function called Calculate, which we'll use to run math operations for addition, subtraction, multiplication, and division.
};

