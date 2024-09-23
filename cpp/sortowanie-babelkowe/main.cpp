#include <iostream>
#include <vector>

using namespace std;

int main(){

	// definicja wektora
	vector<int> numbers({0, 73, 5, 14, 0});


	// sortowanie
	for(int i = 0; i < (numbers.size() - 1); i++)
	{
		for(int j = 0; j < (numbers.size() - 1); j++)
		{
			if(numbers[j] > numbers[j + 1])
			{
				int r = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = r;
			}
		}
	}


	// wyswietlanie
	for(int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}
