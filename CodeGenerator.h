#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

/*******************************************************************************
* 																			   *
* Author: Seth Nuzum                                                           * 
* Date: 11-17-23                                                           	   *
* File: CodeGenerator.h                                                        *
*                                                                              *
* Description: This file contains the description of the CodeGenerator         *
*******************************************************************************/



#include <iostream>
#include <fstream>
#include "LexicalAnalyzer.h"

using namespace std;

/*******************************************************************************
* Class: CodeGenerator                                                         *
*                                                                              *
* Description: This class is designed to generate C++ code for an input Scheme *
*              program.                                                        *
*              The functions in this class will be called by the Syntactic     *
*              analyzer.                                                       *
*******************************************************************************/

class CodeGenerator 
{
    public:
	CodeGenerator (string fileNamePrefix, LexicalAnalyzer * L);
	~CodeGenerator ();
	void WriteCode (int tabs, string code);
    private:
	LexicalAnalyzer * lex;
	ofstream cpp;
};
	
#endif
