#include <iostream>
#include "functions.cpp"
using namespace std;


int main(){

	cout << "Welcome to staircase designer!" << endl << endl;

	double heightOverall;
	cout << "Enter overall height of the staircase [m]: ";
	cin >> heightOverall;

	double lengthOverall;
	cout << "Enter overall length of the staircase [m]: ";
	cin >> lengthOverall;
	cout << endl;

	cout << "-- Validating given data. --" << endl;
	bool possible = validateDimensions(heightOverall, lengthOverall);
	cout << endl;

	if(possible){

		int stepsNumber;
		double stepHeight;
		double stepDepth;

		cout << "-- Calculating dimensions of steps. --" << endl;
		cout << endl;
		calculateDimensions(heightOverall, lengthOverall, stepsNumber, stepHeight, stepDepth);

		cout << "Number of steps: " << stepsNumber << endl << "Height of each step: " << stepHeight << "cm" << endl << "Depth of each step: " << stepDepth << "cm" << endl << endl;

	}else{

		cout << "Sorry, it is impossible to create ergonomic staircase using dimensions given by you." << endl << endl;

	}

	return 0;
}
