#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>
using namespace std;

std::vector<int> randomsVec(10000);
std::vector<int> onesVec(10000, 1);


void bubbleSort(std::vector<int>& vec)
{
    for(int j = 0; j < vec.size(); j++)
    {
	for(int i = 0; i < vec.size() - 1; i++)
	{
	    if(vec[i] > vec[i + 1])
	    {
		int r = vec[i + 1];
		vec[i + 1] = vec[i];
		vec[i] = r;
	    }
	}
    }
}


TEST(BenchmarkTest, RandomBubbleSort) { // 0.809734s

    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(randomsVec);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Random numbers sorting time: " << elapsed_seconds.count() << "s\n";
}


TEST(BenchmarkTest, OnesBubbleSort) { // 0.480738s

    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(onesVec);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Only ones sorting time: " << elapsed_seconds.count() << "s\n";
}


int main(int argc, char **argv) {

    srand(time(0));
    generate(randomsVec.begin(), randomsVec.end(), rand);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

