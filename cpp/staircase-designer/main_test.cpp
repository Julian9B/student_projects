#include <gtest/gtest.h>
#include <cmath>
#include "functions.cpp"
using namespace std;


TEST(StaircaseDesignerTests, Valid1) {

	double heightOverall = 7;
	double lengthOverall = 10;

	int stepsNumber;
	double stepHeight;
	double stepDepth;

	EXPECT_EQ(calculateStaircase(heightOverall, lengthOverall, stepsNumber, stepHeight, stepDepth), true);
	EXPECT_EQ(stepsNumber, 35);
	EXPECT_EQ(round(stepHeight), 20);
	EXPECT_EQ(round(stepDepth), 29);
}

TEST(StaircaseDesignerTests, Valid2) {

	double heightOverall = 3.5;
	double lengthOverall = 5;

	int stepsNumber;
	double stepHeight;
	double stepDepth;

	EXPECT_EQ(calculateStaircase(heightOverall, lengthOverall, stepsNumber, stepHeight, stepDepth), true);
	EXPECT_EQ(stepsNumber, 18);
	EXPECT_EQ(round(stepHeight), 19);
	EXPECT_EQ(round(stepDepth), 29);
}

TEST(StaircaseDesignerTests, Invalid1) {

	double heightOverall = 5;
	double lengthOverall = 3;

	int stepsNumber;
	double stepHeight;
	double stepDepth;

	EXPECT_EQ(calculateStaircase(heightOverall, lengthOverall, stepsNumber, stepHeight, stepDepth), false);
}

TEST(StaircaseDesignerTests, Invalid2) {

	double heightOverall = 10;
	double lengthOverall = 30;

	int stepsNumber;
	double stepHeight;
	double stepDepth;

	EXPECT_EQ(calculateStaircase(heightOverall, lengthOverall, stepsNumber, stepHeight, stepDepth), false);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

