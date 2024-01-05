#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

/*******************************************************************************
*         																	   *
* Author: Seth Nuzum                                                           *
* Date: 11-17-23                                                               *
* File: LexicalAnalyzer.h                                                      *
*                                                                              *
* Description: This file contains the description of the LexicalAnaylzer       *
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

/*******************************************************************************
* Type: token_type                                                             *
*                                                                              *
* Description: The token_type enumerated type is used to identify the tokens   *
*              associated with the lexemes scanned from an input file.         *
*******************************************************************************/

enum token_type
{
	NONE, IDKEY_T, NUMLIT_T, LISTOP1_T, PLUS_T, MINUS_T, GT_T, LT_T,
	TRUE_T, FALSE_T, DIV_T, MULT_T, EQUALTO_T, GTE_T, LTE_T,
	LPAREN_T, RPAREN_T, SQUOTE_T, IDENT_T, IF_T, COND_T,
	DISPLAY_T, NEWLINE_T, AND_T, OR_T, NOT_T, DEFINE_T, LET_T, LISTOP2_T,
	NUMBERP_T, LISTP_T, ZEROP_T, NULLP_T, EOFP_T, MODULO_T, ROUND_T,
	READ_T, ELSE_T, STRLIT_T, ERROR_T, EOF_T, MAX_TOKENS
};

extern string token_names[];

/*******************************************************************************
* Class: LexicalAnalyzer                                                       *
*                                                                              *
* Description: This class is designed to read a Scheme program, recognize      *
*              lexemes, and generate tokens.                                   *
*              The class will also produce a listing with error messages.      *
*******************************************************************************/

class LexicalAnalyzer 
{
    public:
	LexicalAnalyzer (const string & fileNamePrefix);
	~LexicalAnalyzer ();
	token_type GetToken ();
	string GetTokenName (token_type t) const;
	string GetLexeme () const;
	void ReportError (const string & msg);
	ofstream debugFile;	// .dbg
    private:
	ifstream inputFile; 	// .ss 
	ofstream listingFile;	// .lst
	ofstream tokenFile;	// .p1
	string line;
	int linenum;
	int pos;
	string lexeme;
	int errors;
	map <string, token_type> keymap;
	bool GetALine ();
};
	
#endif
