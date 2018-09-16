#include <iostream>
using namespace std;

int main()
{
	int num_seat;
	cin >> num_seat;

	int num_couple = 0;
	char seat[50];

	for (int i = 0; i < num_seat; i++)
		cin >> seat[i];

	for (int i = 0; i < num_seat; i++)
	{
		if (seat[i] == 'L')
			num_couple++;
	}

	if (num_couple == 0)
		num_couple = 2;

	cout << num_seat + 1 - (num_couple / 2) << endl;

	return 0;
}