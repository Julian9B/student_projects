#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

std::vector<int> originalVec(10000); // Tworzymy wektor z 10000 losowymi liczbami

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


int main(int argc, char **argv) {

    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(originalVec.begin(), originalVec.end(), std::rand);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

