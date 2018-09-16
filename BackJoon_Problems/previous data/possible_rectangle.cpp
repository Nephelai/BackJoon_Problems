#include <iostream>
#include <cmath>
using namespace std;

int find_aliquot(int number);

int main()
{
	int in_number;
	cin >> in_number;

	int out_number = 0;

	for (int tmp_number = 1; tmp_number <= in_number; tmp_number++)
	{
		out_number += find_aliquot(tmp_number);
	}

	cout << out_number << endl;

	return 0;
}

int find_aliquot(int number)
{
	int result = 0;

	for (int i = 1; i <= sqrt(number); i++)
	{
		if(number % i == 0)
			result++;
	}

	return result;
}