#include <iostream>
#include <string>
#include "functions.cpp"

using namespace std;

int main() {

    srand(time(0));
    int i = (rand() % 1000) + 1;

    string fb = fizzbuzz(i);

    cout << endl << i << " goes " << (fb != "" ? fb : "nothing") << endl << endl;

    return 0;
}
