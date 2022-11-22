#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Fraction.h"
using namespace std;
// This file contains all of the definitions of the member functions in the Fraction class. They are declared in the Fraction.h header file.

// This is the default constructor for the Fraction class. It sets the fraction equal to 0.
Fraction::Fraction() : numerator(0), denominator(1)
{}

// This constructor sets the fraction equal to a whole number value.
Fraction::Fraction(int& numerator) : numerator(numerator), denominator(1)
{}

// This constructor takes a double for some reason and multiplies it by 100000. I'm not sure what the point of including this one is, but the prompt asked for it.
Fraction::Fraction(double& input)
{
	numerator = input * 100000;
	denominator = 1 * 100000;
}

// This constructor takes a number for the numerator and denominator. If the denominator equals 0, it outputs an error message and sets it to 1.
Fraction::Fraction(int& numerator, int& denominator)
{
	Fraction::numerator = numerator;
	if (denominator != 0)
	Fraction::denominator = denominator;
	else
	{
		Fraction::denominator = 1;
		cout << "Denominator cannot be 0. Denominator set to 1." << endl;
	}
}

// This function takes user input to set the numerator and denominator of a fraction. It will only accept integer values. If the user attempts to input something
// different, such as a char, it will output an error message until it receives an integer input. If the user attempts to set the denominator to 0, it will also
// output an error message.
void Fraction::Input()
{
	cout << "Enter value for fraction numerator and denominator" << endl;
	cout << "Numerator: ";
	cin >> numerator;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only integer values accepted. Enter an integer value. ";
		cin >> numerator;
	}
	cout << endl << "Denominator: ";
	cin >> denominator;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only integer values accepted. Enter an integer value. ";
		cin >> denominator;
	}
	if (denominator == 0)
	{
		cout << "Denominator cannot be 0. Set different value." << endl;
		cin >> denominator;
	}
}

// This function simply prints the numerator and denominator as a fraction.
void Fraction::Print()
{
	cout << numerator << '/' << denominator << endl << endl;
}

// This function performs fraction addition with both fractions in the expression as arguments.
void Fraction::Add(Fraction& firstFraction, Fraction& secondFraction)
{
	// This conditional checks whether or not the fractions have a common denominator, if they do, it will add the numerators.
	if (firstFraction.denominator == secondFraction.denominator)
	{
		firstFraction.numerator = firstFraction.numerator + secondFraction.numerator;
	}
	// If the fractions did not have a common denominator, then it will execute a few multiplications to give the fractions common denominators and adjust the
	// numerators accordingly. It will then add the numerators.
	else
	{
		int newFirstNum = firstFraction.numerator * secondFraction.denominator;
		int newSecondNum = secondFraction.numerator * firstFraction.denominator;
		int commonDenom = firstFraction.denominator * secondFraction.denominator;
		firstFraction.numerator = newFirstNum;
		firstFraction.denominator = commonDenom;
		secondFraction.numerator = newSecondNum;
		secondFraction.denominator = commonDenom;
		
		firstFraction.numerator = firstFraction.numerator + secondFraction.numerator;
	}
}

// This function performs fraction subtraction with both fractions in the expression as arguments.
void Fraction::Subtract(Fraction& firstFraction, Fraction& secondFraction)
{
	// This conditional checks whether or not the fractions have a common denominator, if they do, it will subtract the second numerator from the first.
	if (firstFraction.denominator == secondFraction.denominator)
	{
		firstFraction.numerator = firstFraction.numerator - secondFraction.numerator;
	}
	// If the fractions did not have a common denominator, then it will execute a few multiplications to give the fractions common denominators and adjust the
	// numerators accordingly. It will then subtract the second numerator from the first.
	else
	{
		int newFirstNum = firstFraction.numerator * secondFraction.denominator;
		int newSecondNum = secondFraction.numerator * firstFraction.denominator;
		int commonDenom = firstFraction.denominator * secondFraction.denominator;
		firstFraction.numerator = newFirstNum;
		firstFraction.denominator = commonDenom;
		secondFraction.numerator = newSecondNum;
		secondFraction.denominator = commonDenom;

		firstFraction.numerator = firstFraction.numerator - secondFraction.numerator;
	}
}

// This function performs fraction multiplication with both fractions in the expression as arguments.
void Fraction::Multiply(Fraction& firstFraction, Fraction& secondFraction)
{
	firstFraction.numerator = firstFraction.numerator * secondFraction.numerator;
	firstFraction.denominator = firstFraction.denominator * secondFraction.denominator;
}

// This function performs fraction division with both fractions in the expression as arguments.
void Fraction::Divide(Fraction& firstFraction, Fraction& secondFraction)
{
	firstFraction.numerator = firstFraction.numerator * secondFraction.denominator;
	firstFraction.denominator = firstFraction.denominator * secondFraction.numerator;
}

// This function performs fraction addition with one fraction as an argument and the other as an object.
Fraction Fraction::Add(Fraction& firstFraction)
{
	// This conditional checks whether or not the fractions have a common denominator, if they do, it will add the numerators.
	if (firstFraction.denominator == Fraction::denominator)
	{
		firstFraction.numerator = firstFraction.numerator + Fraction::numerator;
	}
	// If the fractions did not have a common denominator, then it will execute a few multiplications to give the fractions common denominators and adjust the
	// numerators accordingly. It will then add the numerators.
	else
	{
		int newFirstNum = firstFraction.numerator * Fraction::denominator;
		int newSecondNum = Fraction::numerator * firstFraction.denominator;
		int commonDenom = firstFraction.denominator * Fraction::denominator;
		firstFraction.numerator = newFirstNum;
		firstFraction.denominator = commonDenom;
		Fraction::numerator = newSecondNum;
		Fraction::denominator = commonDenom;

		firstFraction.numerator = firstFraction.numerator + Fraction::numerator;
	}
	return firstFraction;
}

// This function performs fraction subtraction with one fraction as an argument and the other as an object. it will subtract the object fraction from the argument.
Fraction Fraction::Subtract(Fraction& firstFraction)
{
	// This conditional checks whether or not the fractions have a common denominator, if they do, it will subtract the object numerator from the argument fraction.
	if (firstFraction.denominator == Fraction::denominator)
	{
		firstFraction.numerator = firstFraction.numerator - Fraction::numerator;
	}
	// If the fractions did not have a common denominator, then it will execute a few multiplications to give the fractions common denominators and adjust the
	// numerators accordingly. It will then subtract the object numerator from the argument fraction.
	else
	{
		int newFirstNum = firstFraction.numerator * Fraction::denominator;
		int newSecondNum = Fraction::numerator * firstFraction.denominator;
		int commonDenom = firstFraction.denominator * Fraction::denominator;
		firstFraction.numerator = newFirstNum;
		firstFraction.denominator = commonDenom;
		Fraction::numerator = newSecondNum;
		Fraction::denominator = commonDenom;

		firstFraction.numerator = firstFraction.numerator - Fraction::numerator;
	}
	return firstFraction;
}

// This function performs fraction multiplication with one fraction as an argument and the other as an object.
Fraction Fraction::Multiply(Fraction& firstFraction)
{
	firstFraction.numerator = firstFraction.numerator * Fraction::numerator;
	firstFraction.denominator = firstFraction.denominator * Fraction::denominator;
	return firstFraction;
}

// This function performs fraction division with one fraction as an argument and the other as an object.
Fraction Fraction::Divide(Fraction& firstFraction)
{
	firstFraction.numerator = firstFraction.numerator * Fraction::denominator;
	firstFraction.denominator = firstFraction.denominator * Fraction::numerator;
	return firstFraction;
}
