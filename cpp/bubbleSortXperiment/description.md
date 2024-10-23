# Sorting tests

## 1. About

In this experiment, we want to check if BubbleSort algorythm has some difference in execution time while sorting only the same numbers.

## 2. Code

We have all necesary code in 'main_test.cpp' file.

### 2.1. Libraries

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>
using namespace std;
```

### 2.2. BubbleSort function

Firstly, we need a function that sorts a vector using BubbleSort algorythm.

```cpp
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
```

### 2.3. GTests

To test function's execution time, we use GTests and Chrono library. In one test, we sort the vector filled with 10000 random numbers, and in the other one - the vector filled only with 10000 ones.

```cpp
std::vector<int> randomsVec(10000); // vector with rando numbers, we are going to fill it later
std::vector<int> onesVec(10000, 1); // vector with ones

TEST(BenchmarkTest, RandomBubbleSort) {

    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(randomsVec);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Random numbers sorting time: " << elapsed_seconds.count() << "s\n";
}


TEST(BenchmarkTest, OnesBubbleSort) {

    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(onesVec);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Only ones sorting time: " << elapsed_seconds.count() << "s\n";
}
```

We call all tests from 'main' function.

```cpp
int main(int argc, char **argv) {

    srand(time(0));
    generate(randomsVec.begin(), randomsVec.end(), rand);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

Other files in folder are compilers and things like that.

## 3. Result

| Vector               | Sorting time |
| -------------------- | ------------ |
| 10000 random numbers | 0.809734s    |
| 10000 ones           | 0.480738s    |

Tab.1.

## 4. Conclusion

The test shows that it took nearly half a time to sort vector filled with ones than to sort vector filled with random numbers.

## Authors

[Julian9B](https://github.com/Julian9B)
