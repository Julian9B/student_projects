# Benchmark If & Switch

## 1. About
This is simple excercise with testing. 
 
We use this code to check which method of choice is faster - If or Switch.

## 2. Code

We have all code in 'main_test.cpp'.

### 2.1 Libraries

Here we have all includes and usings we need:

```cpp
#include <iostream>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>
using namespace std;
```

### 2.2. IF and SWITCH

Firstly, we have two functions: one for If and the other one for Switch.

```cpp
// Function with if
void if_check(int number) {

    if(number > 0) {
	cout << "Number " << number << " is greater than 0." << endl;
    } else {
	cout << "Number " << number << " is smaller or equals 0." << endl;
    }
}

// Function with switch
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
```

### 2.3. Tests

To test it, we use 3 variables for each:

```cpp
int number1 = -3;
int number2 = 0;
int number3 = 41;
```

We use gtests to measure execution time of both functions.

```cpp
// Test of if's efficiency
TEST(BenchmarkTest, IfBenchmark) {

    // Timing start
    auto start = std::chrono::high_resolution_clock::now();

    cout << endl;
    if_check(number1);
    if_check(number2);
    if_check(number3);

    // Timing end
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas wykonania IF: " << elapsed_seconds.count() << endl << endl;
}

// Test of switch's efficiency
TEST(BenchmarkTest, switchBenchmark) {

    // Timing start
    auto start = std::chrono::high_resolution_clock::now();

    cout << endl;
    switch_check(number1);
    switch_check(number2);
    switch_check(number3);

    // Timing end
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas wykonania SWITCH: " << elapsed_seconds.count() << endl << endl;
}
```

### Main program

And finally, we call the tests from 'main' function.

```cpp
int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## 3. Result
![Result in console](../../images/IfSwitchResult.PNG)

## 4. Conclusion
From the test we can see that Switch instruction is faster than If.

## Authors
[Julian9B](https://github.com/Julian9B)
