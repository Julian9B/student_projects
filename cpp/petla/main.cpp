#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	double number;
	cout << "Enter any number: ";
	cin >> number;
	cout << endl;

	ofstream file("result.txt");

	for(; number > 0; number -= 0.1)
	{
		if(number > 7 && number < 10)
		{
			number = 7;
		}

		cout << number << endl;
		file << number << endl;
	}

	file.close();

	return 0;
}
