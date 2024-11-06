#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


bool calculateStaircase(double heightOverall, double lengthOverall, int& stepsNumber, double& stepHeight, double& stepDepth){

	double ratio = heightOverall / lengthOverall;
	double minRatio = 0.5;
	double maxRatio = 0.9;

	bool possible = ratio <= maxRatio && ratio >= minRatio;

	if(possible){
		
		double perfectStepHeight = 20;
		double unroundedStepsNumber = (heightOverall * 100) / perfectStepHeight;

		stepsNumber = round(unroundedStepsNumber);
		stepHeight = (heightOverall * 100) / stepsNumber;
		stepDepth = (lengthOverall * 100) / (stepsNumber - 1);
	}

	return possible;
}
