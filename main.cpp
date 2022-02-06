// Functions_and_Recursion.cpp                   07-02-2022
/*
	Demonstrates:
	Function calls with parameters
	Stack based variables (i.e. automatic variables) created and removed from the stack
	Call-stack (Stack Frame) (Activation Records) [ you must draw diagrams of these ]
	Call-by-Value and Call-by-Reference (Reference Parameters)
	Recursion

*/
#include <iostream>
using namespace std;

// function prototypes
void function1();
int square(int); 
int sum(int, int);
int recursiveSum(int n);
int factorial(int a);
void demoPassByValue(int, double);
void demoPassByReference(int& x, double& z);	// note, Reference parameters

int main()
{
	std::cout << "Function calls and Stack Variables\n";
	function1();	// call a function that returns void (i.e. no return value)

	// Pass-by-Value

	int a = 10;		// 'a' is local (automatic) variable belonging to main()
	int result = square(a); // pass a copy of the value in 'a' as an argument
	cout << a << " squared: " << result << endl; // display a squared

	int x = 3;
	int y = 4;
	result = sum(x, y);	// pass copies of values in x, and y into sum()
	cout << "sum(3,4) = " << result << endl;

	double d = 3.14;
	demoPassByValue(x, d);
	cout << "after calling demoCallByValue() x=" << x << ", d=" << d << endl;

	// Pass-by-Reference

	demoPassByReference(x, d);
	cout << "after calling demoCallByValue() x=" << x << ", d=" << d << endl;
	cout << "x and y have been changed by the function, using references." << endl;


	// Recursion 

	result = recursiveSum(3);  // sum up values from 3 down to 1
	cout << "recursiveSum( 3 ) = " << result << endl;

	int number = 4;
	cout << number << " factorial (4!) = " << factorial(number) << endl;

	return 0;  // indicate successful termination of main()
}

void function1()
{
	int x = 4;
	cout << "In function1(), x = " << x << endl;
	//TODO: draw the call-stack at this point in program's execution
}

// returns the square of an integer
// Call-by-Value
int square(int x)	// x is a parameter  (a local variable in this function)
{                       // x receives a copy of the argument passed in (i.e. 10)
	return x * x;  // "TODO: draw the call stack just before the return
}

int sum(int x, int y)
{
	int sum = x + y;
	return sum;		//TODO: draw the stack frame with variables just before the return
}


// Attempting to change original values passed-by-value will have no effect
// as this function was passed copies of the original values and thus
// has no access to the variables that store the original values
//
void demoPassByValue(int x, double z)
{
	cout << "x = " << x << endl;
	x = 777;	// Changes the local variable x, but does NOT change the value of 
				// x in main().
				// There are two variables called x, one belonging to main, and
				// the other belonging to this function. 
				// 2DO: Draw the call stack, and you will see why this is so.

	z = 8.11;    // has no effect on value of y belonging to main()
}


// Pass by Reference  - (using Reference Parameters)
// Below - x is a reference to an int, z is a reference to a double
//
void demoPassByReference(int& x, double &z)		// either position of the & is fine
{
	cout << "In demoPassByReference() : x = " << x << " and, z = " << z << endl;

	// Parameters - x is of type 'reference to int', and it is bound to x in main()
	//              z is a reference to a double, and is bound to variable d in main()

	x = 2000;	// This WILL change the value of x in main(), because this x is 
				// a reference parameter that refers to the variable x in main().
				// 
				//TODO: Draw the Call-Stack, and you will see why this is so.

	z = 8.11;   // This WILL change the value of y in main(), because z is
				// a reference to variable y in main(). It is an 'alias' or another name for
				// the variable y in main().

	// Reference variables give functions access to variables/objects that
	// were created and exist in other parts of a program.
    // They are very useful in C++ as they are en efficient way of passing
    // data into functions.
				
}

/***********************   RECURSION    ************************/

/*
 *  Recursion - A Recursive function is a function that calls itself.
 *            - we say that the function is making a 'recursive call'
 *
	To understand recursiveSum() it helps to think of summing the numbers in this way:
	To sum all numbers from 3 down to 1
	     result = recursiveSum( 3 )
				=	  3 + recursiveSum( 2 )   [i.e sum = 3 + 'recursive sum of 2']
	which is:         3 +       2          + recursiveSum( 1 )
	which is:         3 +       2          +        1
*/

int recursiveSum(int n)
{
	if (n == 1)			// terminating condition
		return 1;		//

    cout << "... making recursive call recursiveSum(" << n-1 << ")\n";

	return n + recursiveSum(n - 1);  // recursive call
}

int factorial(int a)
{
	if (a > 1)
		return (a * factorial(a - 1));

	return 1;	//TODO: Draw the stack-frame at this point of execution
}

//TODO Draw Stack-Frames for the above recursive function calls.
