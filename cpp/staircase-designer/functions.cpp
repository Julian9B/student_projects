#include <iostream>
#include <cmath>
using namespace std;


bool validateDimensions(double heightOverall, double lengthOverall){
	
	double ratio = heightOverall / lengthOverall;
	double minRatio = 0.5;
	double maxRatio = 0.9;

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
