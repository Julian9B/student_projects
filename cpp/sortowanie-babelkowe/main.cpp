#include <iostream>
#include <vector>

using namespace std;

int main(){

	// definicja wektora
	vector<int> numbers;
	int length;

	cout << "Podaj ilosc elementow: ";
	cin >> length;
	cout << endl;

	for(int i = 0; i < length; i++)
	{
		int a;
		cout << "Podaj element " << i << ": ";
		cin >> a;
		numbers.push_back(a);
	}


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
