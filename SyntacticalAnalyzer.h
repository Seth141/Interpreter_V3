#ifndef SYNTACTICALANALYZER_H
#define SYNTACTICALANALYZER_H

/*******************************************************************************
* Title: Syntactical Analyzer for Scheme to C++ Translator    				   *
* Author: Seth Nuzum                                                           *
* Date: 11-17-23                                                               *
* File: SyntaticalAnalyzer.h                                                   *
*                                                                              *
* Description: This file contains the description of the SyntaticalAnalyzer    *
*******************************************************************************/

#include <iostream>
#include <fstream>
#include "LexicalAnalyzer.h"
#include "CodeGenerator.h" // added for Project 3

using namespace std;

/*******************************************************************************
* Class: SyntacticalAnalyzer                                                   *
*                                                                              *
* Description: This class is designed to determine of the tokens generated     *
*              by the LexicalAnalyzer are in a legal order based on the        *
*              grammar.                                                        *
*              This class will also make calls to the CodeGenerator functions. *
*******************************************************************************/

class SyntacticalAnalyzer 
{
    public:
	SyntacticalAnalyzer (const string & fileNamePrefix);
	~SyntacticalAnalyzer ();
    private:
	LexicalAnalyzer * lex;
	CodeGenerator * cg; 
	ofstream ruleFile;
	token_type token;

	void program ();
	void more_defines ();
	void define ();
	void stmt_list ();
	void stmt ();
	void literal ();
	void quoted_lit ();
	void logical_lit ();
	void more_tokens ();
	void param_list ();
	void else_part ();
	void stmt_pair ();
	void stmt_pair_body ();
	void assign_pair ();
	void more_assigns ();
	void action ();
	void any_other_token ();
	void handleNumberDisplay();
    void handleArithmeticOperation();
};

#endif
