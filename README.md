# Student projects

## About
These are various projects done on my school exercises. They contain some C++ code, as well as Python and HTML.

## Credits
To Mr. Filipak, some nice teacher.  
[His Github](https://github.com/marcin-filipiak)

## Codes
C++ code from one of my exercises:  

```cpp
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
```

## Screenshots
Results of different tests in console:
 
![Result of Bubblesort vs Quicksort tests](images/TestResult.PNG)
![Result of Fizzbuzz tests](images/FizzbuzzResult.PNG)
![Result of If vs Switch tests](images/IfSwitchResult.PNG)

## Authors
[Julian9B](https://github.com/Julian9B)
