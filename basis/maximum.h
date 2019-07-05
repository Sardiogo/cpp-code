#pragma once
// maximum function that determines the largest of three values. 
/*
	Overloaded functions are typically used to perform similar operations that may involve different program logic on different data types. 
	If the program logic and operations are identical for each data type, overloading may be performed more compactly and conveniently by using	function templates. 
	You write a single function template definition. Given the argument	types provided in calls to this function, C++ automatically generates separate function template
	specializations to handle each type of call appropriately. Thus, defining a single function	template essentially defines a whole family of overloaded functions.
*/
/*
	All function template definitions begin with the template keyword followed by a template parameter list to the function template enclosed in angle brackets(< >).
	Every parameter in the template parameter list (< >) (each is referred to as a formal type parameter) is preceded by keyword typename or keyword class (which are synonyms).
	The formal type parameters are placeholders for fundamental types or user-defined types.
	These placeholders are used to specify the types of the function’s parameters, to specify the function’s return type and to declare variables within the body of the function definition.
	A function template is defined like any other function, but uses the formal type parameters as placeholders for actual data types.
*/
/*
	The function template in Fig. 15.12 declares a single formal type parameter T as a placeholder for the type of the data to be tested by function maximum. 
	The name of a type parameter must be unique in the template parameter list for a particular template definition. 
	When the compiler detects a maximum invocation in the program source code, the type of the data passed to maximum is substituted for T throughout the template definition,
	and C++ creates a complete source-code function for determining the maximum of three values of the specified data type. 
	Then the newly created function is compiled. Thus, templates are a means of code generation for a range of similar functions.
*/

template < class T > // Or: template < typename T >
T maximum(T value1, T value2, T value3)
{
	T maximumValue = value1; // assume value1 is maximum
	// determine whether value2 is greater than maximumValue
	if (value2 > maximumValue)
		maximumValue = value2;
	// determine whether value3 is greater than maximumValue
	if (value3 > maximumValue)
		maximumValue = value3;
	return maximumValue;
}

/*
	// demonstrate maximum with int values
	int int1, int2, int3;
	cout << "Input three integer values: ";
	cin >> int1 >> int2 >> int3;
	// invoke int version of maximum
	cout << "The maximum integer value is: " << maximum( int1, int2, int3 );
	// For example, the function template specialization created for type int replaces each occurrence of T with int as follows:
	int maximum( int value1, int value2, int value3 )
	{
		int maximumValue = value1; // assume value1 is maximum
		// determine whether value2 is greater than maximumValue
		if ( value2 > maximumValue )
			maximumValue = value2;
		// determine whether value3 is greater than maximumValue
		if ( value3 > maximumValue )
			maximumValue = value3;
		return maximumValue;
	}
*/