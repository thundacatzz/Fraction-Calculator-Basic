#pragma once
// This header file contains all of the declarations for the Fraction class. They are further detailed in the Fraction.cpp file
class Fraction
{
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int& numerator);
	Fraction(double&);
	Fraction(int& numerator, int& denominator);

	void Input();
	void Print();

	Fraction Add(Fraction&);
	Fraction Subtract(Fraction&);
	Fraction Multiply(Fraction&);
	Fraction Divide(Fraction&);

	void Add(Fraction&, Fraction&);
	void Subtract(Fraction&, Fraction&);
	void Multiply(Fraction&, Fraction&);
	void Divide(Fraction&, Fraction&);
};

