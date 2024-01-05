/*******************************************************************************
* Title: Code Generator for Scheme to C++ Translator          				   *
* Author: Seth Nuzum                                                      	   *
* Date: 11-17-23                                                               *
* File: CodeGenerator.cpp                                                      *
*                                                                              *
* Description: This file contains the implementation of the CodeGenerator      *
*******************************************************************************/


#include <iostream>
#include <fstream>
#include "CodeGenerator.h"

using namespace std;

/********************************************************************************/
/* This function will initialize the CodeGenerator object. It will open and     */
/* write the initial lines to a .cpp file for the PL460 program translation.	*/
/********************************************************************************/
CodeGenerator::CodeGenerator (string fileNamePrefix, LexicalAnalyzer * L)
{
	lex = L;
	string cppname = fileNamePrefix + ".cpp"; 
	cpp.open (cppname.c_str());
	cpp << "// Autogenerated PL460 to C++ Code\n";
	cpp << "// File: " << cppname << "\n\n";
	cpp << "#include <iostream>\n";
	cpp << "#include \"Object.h\"\n";
	cpp << "using namespace std;\n\n";
}

/********************************************************************************/
/* This function will be called when the CodeGenerator object is deleted. It    */
/* close the generated .cpp file.						                        */
/********************************************************************************/
CodeGenerator::~CodeGenerator ()
{
	cpp.close();
}

/********************************************************************************/
/* This function will be called by the SyntacticAnalyzer to write lines of C++  */
/* code to the .cpp file.							                            */
/********************************************************************************/
void CodeGenerator::WriteCode (int tabs, string code)
{
	for (int t = 0; t < tabs; t++)
		cpp << '\t';
	cpp << code;
}
