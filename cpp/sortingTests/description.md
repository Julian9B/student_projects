# Sorting tests

## 1. About
This is simple excercise with sorting and testing. 
 
The code sorts vector in 2 ways - Quicksort and Bubblesort, using unit testing. It also measures time and says which method is faster.

## 2. Code

### 2.1. Template

The file 'main_test.cpp', which we can see here, I started from test template, including only Quicksort:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

// Funkcja sortująca wektor za pomocą QuickSort
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

// Test wydajności sortowania QuickSort
TEST(BenchmarkTest, QuickSortBenchmark) {

    std::vector<int> originalVec(10000); // Tworzymy wektor z 10000 losowymi liczbami
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(originalVec.begin(), originalVec.end(), std::rand);
    
    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(originalVec); // Sortujemy wektor

    // Koniec pomiaru czasu
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

Now, in the file we have two functions, creating copy of vector and sorting it's elements - one using BubbleSort, and the other one using QuickSort.

```cpp
// Funkcja sortująca wektor za pomocą QuickSort
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

// Funkcja sortująca wektor za pomocą bubblesort
void bubbleSort(std::vector<int>& originalVec)
{
    std::vector<int> vec = originalVec;

    for(int j = 0; j < vec.size() - 1; j++)
    {
	for(int i = 0; i < vec.size() - 1; i++)
	{
	    if(vec[i] > vec[i + 1])
	    {
		int r = vec[i];
		vec[i + 1] = vec[i];
		vec[i] = r;
	    }
	}
    }
}
```

We test execution time of them both in gtests.

```cpp
// Test wydajności sortowania QuickSort
TEST(BenchmarkTest, QuickSortBenchmark) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(originalVec); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}

// Test wydajności sortowania bubblesort
TEST(BenchmarkTest, BubbleSortBenchmark) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(originalVec); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}
```

To compare them, we create vector with 10000 random numbers, and send it to both algorithms.

```cpp
std::vector<int> originalVec(10000); // Tworzymy wektor z 10000 losowymi liczbami
```

```cpp
int main(int argc, char **argv) {

    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(originalVec.begin(), originalVec.end(), std::rand);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

Other files in folder are compilers and things like that.

## 3. Result
![Result in console](../../images/TestResult.PNG)

## 4. Conclusion
From the test we can clearly conclude that Quicksort is a lot faster than Bubblesort.

## Authors
[Julian9B](https://github.com/Julian9B)
