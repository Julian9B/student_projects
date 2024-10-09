#include <iostream>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>
using namespace std;

int number1 = -3;
int number2 = 0;
int number3 = 41;

// Funkcja sprawdzająca if
void if_check(int number) {

    if(number > 0) {
	cout << "Number " << number << " is greater than 0." << endl;
    } else {
	cout << "Number " << number << " is smaller or equals 0." << endl;
    }
}

// Funkcja sprawdzająca switch
void switch_check(int number){

    switch(number > 0) {
	case true:
	    cout << "Number " << number << " is greater than 0." << endl;
	    break;
	default:
	    cout << "Number " << number << " is smaller or equals 0." << endl;
	    break;
    }
}

// Test wydajności if
TEST(BenchmarkTest, IfBenchmark) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    cout << endl;
    if_check(number1);
    if_check(number2);
    if_check(number3);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas wykonania IF: " << elapsed_seconds.count() << endl << endl;
}

// Test wydajności switch
TEST(BenchmarkTest, switchBenchmark) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    cout << endl;
    switch_check(number1);
    switch_check(number2);
    switch_check(number3);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas wykonania SWITCH: " << elapsed_seconds.count() << endl << endl;
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

