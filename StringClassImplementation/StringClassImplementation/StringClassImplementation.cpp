// StringClassImplementation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"

int main()
{
	String s1; // Default Constructor;
	cout << "s1 : " << s1 << endl;

	String s0("Initial string"); //Parameterised Constructor
	cout << "s0 : " << s0 << endl;

	String s2(s0); // Copy Constructor
	cout << "s2 : " << s2 << endl;

	String s3(s0, 8, 3); //Substring Constructor
	cout << "s3 : " << s3 << endl;

	String s4("A character sequence");
	cout << "s4 : " << s4 << endl;

	String s5("Another character sequence", 12);
	cout << "s5 : " << s5 << endl;

	String s6a(10, 'x');
	cout << "s6a : " << s6a << endl;

	String s6b(10, 42);
	cout << "s6b : " << s6b << endl;

    return 0;
}

