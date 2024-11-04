# Staircase designer

## 1. About

This exercise is about creating app that can design a stairs based on user input data. We start from a console app and modify it to be a window app later.

### 1.1. Use case

| USE CASE       | Staircase designer app |
| -------------- | ---------------------- |
| ACTOR          | User of system |
| GOAL           | User wants to get data about stairs steps' height and depth, based on height and length of entire staircase |
| BASIC FLOW     | 1. User opens the app. <br> 2. User enters height and length of the staircase [m] into 'Staircase height' and 'Staircase length' fields. <br> 3. App defines that it is possible to create a staircase with user's data. <br> 4. App calculates number, height and depth of the steps [cm] and returns them to the user. |
| EXCEPTION FLOW | 1. User opens the app. <br> 2. User enters height and length of the staircase [m] into 'Staircase height' and 'Staircase length' fields. <br> 3. App defines that it is impossible to create a staircase with user's data. <br> 4. App returns an error message to the user. |

Tab.1.

### 1.2. The problem

If given height and length are very unreal (i.e. 10m/1m), the program should return invalid data message. To do that, we need to check if their height to length ratio fits in ergonomic dimensions of staircase. 
 
To calculate height and depth of the steps, we first need to calculate their number. We do that by dividing staircase's height by height of ergonomic step's height and round the result. Then, the we divide the height of the staircase by number of steps to get exact height of single step. Finally, we divide the length of staircase by number of steps minus one (because the last step is already the next floor so we don't need to count it) to get the depth of single step.

### 1.3. Plan for code

We need two functions - one for validating user data, and the other one for calculating dimensions. We're going to have them in 'functions.cpp' file. In the 'main.cpp' file we're going to get user's input, call the functions and calculate data or return invalid message, based on first function's result.

## 2. Code

### 2.1. Console app

We start our program as console app.

#### Functions file

We have two functions in file 'functions.cpp' - one function validates input data, and the other one calculates output data.

```cpp
#include <iostream>
#include <cmath>
using namespace std;


bool validateDimensions(double heightOverall, double lengthOverall){

	double ratio = heightOverall / lengthOverall; // Height to lentgh ratio
	double minRatio = 0.5;
	double maxRatio = 0.9;

	// Checking if height to length ratio fits in our limits
	if(ratio <= maxRatio && ratio >= minRatio){
		return true;
	}

	return false;
}


void calculateDimensions(double heightOverall, double lengthOverall, int& stepsNumber, double& stepHeight, double& stepDepth){
	
	// Calculating number of steps
	double perfectStepHeight = 20;
	double unroundedStepsNumber = (heightOverall * 100) / perfectStepHeight;
	stepsNumber = round(unroundedStepsNumber);

	// Calculating step's height
	stepHeight = (heightOverall * 100) / stepsNumber;

	// Calculating step's depth
	stepDepth = (lengthOverall * 100) / (stepsNumber - 1);
}
```

#### Main program
 
In the file 'main.cpp' we have 'main' function that gets overall height and length of the staircase from user, then decides whether to calculate output or return an error message, based on result of validating function.

```cpp
#include <iostream>
#include "functions.cpp"
using namespace std;


int main(){

	cout << "Welcome to staircase designer!" << endl << endl;

	// User input
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

	// Checking if the user data is valid
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
```

Other files are useful to compile the program.

### 2.2 Window app

Next, we want to turn our console app into window app.

## 3. Result

### 3.1. Result of console app

### 3.2. Result of window app

## 4. Conclusion

## Authors
[Julian9B](https://github.com/Julian9B)
