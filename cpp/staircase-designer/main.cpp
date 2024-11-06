#include <iostream>
#include "functions.cpp"
using namespace std;


int main(){

	cout << "Welcome to staircase designer!" << endl << endl;

	double heightOverall;
	cout << "Staircase height [m]: ";
	cin >> heightOverall;

	double lengthOverall;
	cout << "Staircase length [m]: ";
	cin >> lengthOverall;
	cout << endl;

	int stepsNumber;
	double stepHeight;
	double stepDepth;

	if(calculateStaircase(heightOverall, lengthOverall, stepsNumber, stepHeight, stepDepth)){

		cout << "Number of steps: " << stepsNumber << endl << "Height of each step: " << stepHeight << "cm" << endl << "Depth of each step: " << stepDepth << "cm" << endl << endl;
	}else{

		cout << "Sorry, it is impossible to create ergonomic staircase using dimensions given by you." << endl << endl;
	}

	return 0;
}
