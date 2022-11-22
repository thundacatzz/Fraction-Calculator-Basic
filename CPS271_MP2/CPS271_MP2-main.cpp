#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Fraction.h"
using namespace std;

// This program contains a loop that will continue until the user decides to quit. It performs the arithmetic functions of addition, subtraction, multiplication,
// and division on two fractions at a time.
// Written by Logan Skura, 10/5/2022
int main()
{
	// These variables are used throughout the main. They are declared here so they don't need to be declared in each operation.
	char operation = 'X';
	char decision = '0';
	Fraction firstFraction;
	Fraction secondFraction;
	cout << "Welcome to the fraction calculator." << endl << endl;

	// This loop will perform calculations until the user decides to quit.
	while (true)
	{
		cout << "Which operation would you like to perform? Enter A for addition, S for subtraction, M for multiplication, D for division, or Q/q to quit. " << endl;
		cin >> operation;
		// This conditional tests to see if the user wants to quit or has entered a wrong input. If they have entered a correct input for one of the operations,
		// it will ask them to input values for the fractions they'd like to calculate with.
		if (operation == 'A' || operation == 'S' || operation == 'M' || operation == 'D')
		{
			cout << "Enter your first fraction." << endl;
			firstFraction.Input();
			cout << "Your first fraction is: ";
			firstFraction.Print();
			cout << "Enter your second fraction." << endl;
			secondFraction.Input();
			cout << "Your second fraction is: ";
			secondFraction.Print();
		}
		// This switch performs one of the arithmetic functions, quits the program, or outputs an error message based on the user input.
		switch (operation)
		{
		case 'A':
			// This "function 1 or 2" decision point in each operation allows the user to choose either the arithmetic function with 2 parameters or 1 parameter
			// for testing purposes. The answer will be the same either way.
			cout << "Would you like to use function 1 or 2? Enter 1 or 2 to choose. ";
			cin >> decision;
			if (decision == '1')
			{
				firstFraction.Add(firstFraction, secondFraction);
				cout << "The answer is: ";
				firstFraction.Print();
				break;
			}
			else if (decision == '2')
			{
				secondFraction.Add(firstFraction);
				cout << "The answer is: ";
				firstFraction.Print();
				break;
			}
			else
			break;
		case 'S':
			cout << "Would you like to use function 1 or 2? Enter 1 or 2 to choose. ";
			cin >> decision;
			if (decision == '1')
			{
				firstFraction.Subtract(firstFraction, secondFraction);
				cout << "The answer is: ";
				firstFraction.Print();
				break;
			}
			else if (decision == '2')
			{
				secondFraction.Subtract(firstFraction);
				cout << "The answer is: ";
				firstFraction.Print();
				break;
			}
			else
			break;
		case 'M':
			cout << "Would you like to use function 1 or 2? Enter 1 or 2 to choose. ";
			cin >> decision;
			if (decision == '1')
			{
				firstFraction.Multiply(firstFraction, secondFraction);
				cout << "The answer is: ";
				firstFraction.Print();
				break;
			}
			else if (decision == '2')
			{
				secondFraction.Multiply(firstFraction);
				cout << "The answer is: ";
				firstFraction.Print();
				break;
			}
			else
			break;
		case 'D':
			cout << "Would you like to use function 1 or 2? Enter 1 or 2 to choose. ";
			cin >> decision;
			if (decision == '1')
			{
				firstFraction.Divide(firstFraction, secondFraction);
				cout << "The answer is: ";
				firstFraction.Print();
				break;
			}
			else if (decision == '2')
			{
				secondFraction.Divide(firstFraction);
				cout << "The answer is: ";
				firstFraction.Print();
				break;
			}
			else
			break;
		// These 2 cases, 'Q' and 'q', quit the program.
		case 'Q':
			return 1;
		case 'q':
			return 1;
		// If anything but the defined cases are entered, the program will prompt the user to enter a correct input and then restart the loop.
		default:
			cout << operation << " is not a valid choice. Please choose A, S, M, D, or Q/q to quit." << endl;
			break;
		}
	}
	return 1;
}