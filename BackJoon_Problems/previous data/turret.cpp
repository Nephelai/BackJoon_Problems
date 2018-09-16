#include <iostream>
#include <cmath>
using namespace std;

int testcase;

void Calculator(int arr[])
{
	int min_rad = arr[2];
	int max_rad = arr[5];
	if (min_rad > max_rad)
		swap(min_rad, max_rad);

	double des = sqrt(pow(arr[3] - arr[0], 2) + pow(arr[4] - arr[1], 2));

	if (arr[0] == arr[3] && arr[1] == arr[4] && arr[2] == arr[5])
		cout << "-1" << endl;
	else if (des > min_rad + max_rad || des < max_rad - min_rad)
		cout << "0" << endl;
	else if (des == min_rad + max_rad || des + min_rad == max_rad)
		cout << "1" << endl;
	else
		cout << "2" << endl;
}

int main()
{
	int arr[6];
	int idx = 0;

	cin >> testcase;

	while (testcase != 0)
	{
		while (cin >> arr[idx])
		{
			idx++;
			if (idx == 6)
				break;
		}

		Calculator(arr);

		idx = 0;
		testcase--;
	}


	return 0;
}