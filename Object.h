#ifndef OBJECT_H
#define OBJECT_H

/*******************************************************************************
*    																		   *
* Author: Seth Nuzum                                                           *
* Date: 11-17-23                                                               *
* File: LexicalAnalyzer.h                                                      *
*                                                                              *
* Description: This file contains the description of the Object class and two  *
*              related classes: rational and boolean.                          *
*******************************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

enum obj_type {NONE, INT, REAL, STRING, RATIONAL, BOOLEAN, LIST};
	
/*****************************************************************
* Description: The following is the definition of a class        *
*              called rational. Objects of the rational class    *
*              will contain a fraction's numerator (signed)      *
*              and denominator (unsigned > 0).                   *
*****************************************************************/

class rational
{
    public:

	// Constructors
	rational ();
	rational (const rational & R);
	
	// Destructor 
	~rational (); 
	
	//Assignment operator
	rational & operator = (const rational & R);
	
	// Input and Output Operators
	friend istream & operator >>
				(istream & input, rational & R);
	friend ostream & operator <<
				(ostream & output, const rational & R);

	
	// Additional constructors constructors
	rational (const int numerator, const int denominator);
	rational (const int I);
	rational (const double D);
	
	// Logical Operators
	bool operator != (const rational & R) const;
	bool operator > (const rational & R) const;
	bool operator >= (const rational & R) const;
	bool operator == (const rational & R) const;
	bool operator < (const rational & R) const;
	bool operator <= (const rational & R) const;
	
	// Arithmetic Operators
	rational operator + (const rational & R) const;
	rational operator / (const rational & R) const;
	rational operator - (const rational & R) const;
	rational operator * (const rational & R) const;
	rational operator *= (const rational & R);
	rational operator += (const rational & R);
	rational operator -= (const rational & R);
	rational operator /= (const rational & R);
	rational operator ++ (); // Pre
	rational operator ++ (int); // Post
	rational operator -- (); // Pre
	rational operator -- (int); // Post
	
	// Conversion Operators
	operator int () const;
	operator float () const;
	operator double () const;
	friend string to_string (const rational & R);
	rational round ();				
	rational round (unsigned D);	
	friend int round (const rational & R);
	friend rational round (const rational & R, unsigned D);
	
	// Other Methods
	rational reduce ();			
	rational reciprocal () const;	

    private:
	int num;
	int denom;
};

/*****************************************************************
* Description: The following is the definition of a class        *
*              called boolean. Objects of the boolean class      *
*              will contain a boolean value. Output will be      *
*              #f if value is false (0) and #t otherwise.        *
*****************************************************************/

class boolean
{
    public:
	boolean ();
	boolean (const int B);
	operator bool () const;
	friend ostream & operator <<
			(ostream & output, const boolean & B);
    private:
	bool value;
};

/*****************************************************************
* Description: The following is the definition of a class        *
*              called Object. Objects of the Object class        *
*              will contain a a variety of scalar types and      *
*              lists.                                            *
*****************************************************************/
class Object
{
    public:
	Object();
	Object (const int & value);
	Object (const double & value);
	Object (const string & value);
	Object (const rational & value);
	Object (const boolean & value);
	boolean operator == (const Object & O) const;
	boolean operator != (const Object & O) const;
	boolean operator < (const Object & O) const;
	boolean operator <= (const Object & O) const;
	boolean operator > (const Object & O) const;
	boolean operator >= (const Object & O) const;
	Object operator + (const Object & O) const;
	Object operator - (const Object & O) const;
	Object operator * (const Object & O) const;
	Object operator / (const Object & O) const;
	Object operator % (const Object & O) const;
	boolean operator ! () const;
	operator bool () const;
	friend boolean numberp (const Object & O);
	friend boolean symbolp (const Object & O);
	friend boolean listp (const Object & O);
	friend boolean zerop (const Object & O);
	friend boolean nullp (const Object & O);
	friend boolean stringp (const Object & O);
	friend Object listop (const string & S, const Object & O);
	friend Object listop (const string & S, const Object & O1, const Object O2);
	friend Object round (const Object & O);
	friend ostream & operator << (ostream & outs, const Object & O);
	friend istream & operator >> (istream & ins, Object & O);
	string getType () const;
    private:
	Object (stringstream & ss);
	void MakeName ();
	obj_type type;
	string name;
	int intval;
	double realval;
	string strval;
	rational ratval;
	boolean boolval;
	vector <Object> listval;
};

Object read (istream & ins);

#endif
