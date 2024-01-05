/*******************************************************************************
* Title: Driver program for Scheme to C++ Translator                           *
* Author: Seth Nuzum                                                           *
* Date: 11-17-23                                                               *
* Description: This file contains the driver program for the Interpreter.      *
*******************************************************************************/


#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "SyntacticalAnalyzer.h"

int main (int argc, char * argv[])
{
	if (argc < 2)
	{
		cerr << "Usage: " << argv[0] << " <filename>\n";
		exit (1);
	}
	cout << "Input file: " << argv[1] << endl << endl;
	string name = argv[1];
	string extension;
	if (name.length() > 6)
		extension = name.substr (name.length()-6, 6);
	if (extension != ".pl460")
	{
		cout << "Invalid file extension; must be '.pl460'\n";
		exit (1);
	}
	name = name.substr (0, name.length()-6);
	SyntacticalAnalyzer parser (name);
	return 0;
}
