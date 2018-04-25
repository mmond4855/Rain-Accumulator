//Author - Mario D. Mondelice
//Date Written - May 2, 2016
//This program will calculate the amount of rainfall in a year.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//function prototypes
void welcomeMessage();
void goodbyeMessage();

int main()
{
	//declarations of variables
	string monthName[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	const int months = 12;
	double rainfall[months] = { 0.0 };
	double totalRainfall = 0.0;
	double averageRainfall = 0.0;
	double highestRainfall = 0.0;
	double lowestRainfall = 0.0;
	string HIGH_MONTH = " ";
	string LOW_MONTH = " ";
	char process = ' ';
	string city = " ";

	//calls the hello message
	welcomeMessage();

	//Ask the user if they would like to use the program.
	cout << "Would you like to use this program to calculate rainfall? ";
	cin >> process;
	process = toupper(process);

	system("cls");

	do
	{
		//Get the user to input the city that they are in.
		cout << "Enter the name of your city: ";
		cin >> city;

		for (int order = 0; order < months; order++)
		{
			//Get the user to enter the amount of rainfall for each month.
			cout << "Enter the amount of rainfall for month of " << monthName[order] << ": ";
			cin >> rainfall[order];

			if (rainfall[order] < 0) //If the user put a rainfall less than 0.
			{
				do
				{
					//Get the user to enter a number greater than 0.
					cout << "Please enter a number greater than 0 for " << monthName[order] << ": ";
					cin >> rainfall[order];
				} while (rainfall[order] < 0);
				//end while loop
				totalRainfall += rainfall[order];
			}
			else
			{
				totalRainfall += rainfall[order];
			}
			//end if statement
		}
		//end for loop.
		
		system("cls");

		//Calculates the average rainfall.
		averageRainfall = totalRainfall / months;

		//Gets the highest rainfall.
		highestRainfall = rainfall[0];

		for (int order = 1; order < months; order++)
		{
			if (rainfall[order] > highestRainfall)
			{
				highestRainfall = rainfall[order];
				HIGH_MONTH = monthName[order];
			}
		}

		//Gets the lowest rainfall.
		lowestRainfall = rainfall[0];

		for (int order = 1; order < months; order++)
   {
	   if (rainfall[order] < lowestRainfall)
	   {
		   lowestRainfall = rainfall[order];
		   LOW_MONTH = monthName[order];
	   }
   }

		//Displays the totals.
		cout << fixed << setprecision(2);
		cout << endl << "The total amount of rainfall for " << city << " is " << totalRainfall << " inches.";
		cout << endl << "The average amount of rainfall for " << city << " is " << averageRainfall << " inches.";
		cout << endl << HIGH_MONTH << " has the highest rainfall amount with " << highestRainfall << " inches.";
		cout << endl << LOW_MONTH << " has the lowest rainfall amount with " << lowestRainfall << " inches.";

		//Ask the user if they would like to do it again?
		cout << endl << "Would you like to find rainfall amounts for another city? ";
		cin >> process;
		process = toupper(process);

	} while (process == 'Y');

	//calls the goodbye message.
	goodbyeMessage();

	cout << endl << endl;
	return 0;
}

void welcomeMessage()//function header for welcome message.
{
	cout << endl << "-----------------------------------------------";
	cout << endl << "     Welcome to the RAINFALL ACCCUMULATOR      ";
	cout << endl << "-----------------------------------------------";
	cout << endl;
	return;
}

void goodbyeMessage() //function header for goodbye message.
{
	cout << endl << "------------------------------------------------";
	cout << endl << "Thank you for using the RAINFALL ACCUMULATOR.";
	cout << endl << "GOODBYE :D.";
	cout << endl << "------------------------------------------------";
	return;
}