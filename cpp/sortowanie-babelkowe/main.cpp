#include <iostream>
#include <vector>

using namespace std;

int main(){

	// definicja wektora
	vector<int> numbers;
	int value = 1;

	while(value != 0){
		cout << "Podaj kolejny element lub '0' aby zakonczyc: ";
		cin >> value;
		numbers.push_back(value);
	}
	cout << endl;


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
	cout << endl;

	return 0;
}
