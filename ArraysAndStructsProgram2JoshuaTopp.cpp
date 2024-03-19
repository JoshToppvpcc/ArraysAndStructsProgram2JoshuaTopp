// ArraysAndStructsProgram2JoshuaTopp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include <iomanip>
#include <fstream>
using namespace std;
const int MaxRows = 20;
const int NCols = 8;
const string inFile = "RunnersText.txt";
ifstream inFilie;

//Read the data off of the input file
// Preconditions - needs a place to send the names of the runners and they miles they ran, which are empty arrrays. 
// Post conditions - Return the number of rows (names) on the file and store the data into the arrays. 
int GetMilesRan(string runners[], double milesRan[][NCols], int MaxRows);

// Calc. Total miles and average miles ran per day for each runner
// Preconditions - recieves the number of miles ran each day for each runner. 
// Post conditions - The average miles per day of each runner is calculated and output in the right spot. 
void CalcAverage(double milesRan[][NCols], double rows);


//Clac toal miles of each runner in that week and display it. 
//Preconditions - Table of milesRan[i][j] has to be accessible so the numbers can be added and returned. 
// Post condition - The total miles of each runners' week is out put next to their average at the end of the table. 
void CalcTotal(double milesRan[][NCols], double rows);


int main()
{
	ifstream inFile;
	inFile.open("RunnersText.txt");
	string runners[MaxRows];
	double milesRan[MaxRows][NCols];
	double numRecords;
	numRecords = GetMilesRan(runners, milesRan, MaxRows);
	CalcAverage(milesRan, numRecords);
	CalcTotal(milesRan, numRecords);
	for (int i = 0; i < numRecords; i++) {
		cout << setw(5) << runners[i] << setw(3) << " ";
		for (int j = 0; j < NCols; j++) {
			cout << milesRan[i][j] << setw(3) << " ";
		}
		cout << endl;
		//cout << CalcAverage(milesRan[i][j], MaxRows);
		//cout << CalcTotal(milesRan[i][j], MaxRows) << endl;
	}
}

int GetMilesRan(string runners[], double milesRan[][NCols], int MaxRows) {
	ifstream  inFile;
	int rows = 0;
	inFile.open("RunnersText.txt");
	inFile >> runners[rows];
	while (!inFile.eof() && !(rows >= MaxRows)) {
		for (int i = 0; i < NCols - 2; i++) {
			inFile >> milesRan[rows][i];
		}
		rows++;
		inFile >> runners[rows];
	}
	inFile.close();
	return rows;


}
void CalcAverage(double milesRan[][NCols], double rows) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < NCols - 2; j++)
			sum += milesRan[i][j];
		(milesRan[i][NCols - 2] = sum / (NCols - 2));
	}
}
void CalcTotal(double milesRan[][NCols], double rows) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < NCols - 2; j++)
			sum += milesRan[i][NCols - 2];
	}
}