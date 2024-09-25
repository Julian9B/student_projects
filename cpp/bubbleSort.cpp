#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& vec)
{
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
