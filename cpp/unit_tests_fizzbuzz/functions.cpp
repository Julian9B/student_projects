#include <iostream>
#include <string>
using namespace std;

string fizzbuzz(int number) {

    string result = "";

    if(number % 3 == 0) {
	result += "Fizz";
    }

    if(number % 5 == 0) {
	result += "Buzz";
    }

    return result;
}
