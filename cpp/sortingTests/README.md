# Sorting tests

## 1. About

This is C++ excercise about sorting and testing. The code sorts vector in 2 ways - Quicksort and Bubblesort, using unit testing. It also measures time and says which method is faster.

## 2. Code

### 2.1. Template

I started the file 'main_test.cpp' from test template, including only Quicksort:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

// QuickSort function
void quickSort(std::vector<int>& vec)
{
    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}

// QuickSort efficiency test
TEST(BenchmarkTest, QuickSortBenchmark) {

    std::vector<int> originalVec(10000); // We create vector with 10000 random numbers
    std::srand(std::time(0)); // We initialize random numbers generator
    std::generate(originalVec.begin(), originalVec.end(), std::rand);
    
    // Timing start
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(originalVec); // We sort our vector

    // Timing end
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### 2.2. Current code

Now, in the file we have two functions, creating copy of original vector and sorting it's elements - one using BubbleSort, and the other one using QuickSort.

```cpp
// QuickSort function
void quickSort(std::vector<int>& originalVec)
{
    std::vector<int> vec = originalVec;

    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}

// BubbleSort function
void bubbleSort(std::vector<int>& originalVec)
{
    std::vector<int> vec = originalVec;

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

We test execution time of them both in gtests, using chrono library.

```cpp
// QuickSort efficiency test
TEST(BenchmarkTest, QuickSortBenchmark) {

    // Timing start
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(originalVec); // Sortujemy wektor

    // Timing end
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}

// BubbleSort efficiency test
TEST(BenchmarkTest, BubbleSortBenchmark) {

    // Timing start
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(originalVec); // Sortujemy wektor

    // Timing end
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}
```

To compare them, we create vector with 10000 random numbers, and send it to both algorithms.

```cpp
std::vector<int> originalVec(10000); // We create vector with 10000 random numbers

int main(int argc, char **argv) {

    std::srand(std::time(0)); // We initialize random numbers generator
    std::generate(originalVec.begin(), originalVec.end(), std::rand);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

Other files in folder are compilers and things like that.

## 3. Result

![Result in console](../../images/TestResult.PNG)
Img. 1.

Test show that it took 13ms for QuickSort to sort our vector, while it took 475ms for BubbleSort to do that.

## 4. Conclusion

From the test we can clearly conclude that Quicksort is a lot faster than Bubblesort.

## Authors
[Julian9B](https://github.com/Julian9B)
