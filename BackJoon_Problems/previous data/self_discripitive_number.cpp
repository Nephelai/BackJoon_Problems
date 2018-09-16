#include <iostream>
using namespace std;

int testcase;

int main()
{
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int temp_num;
		cin >> temp_num;

		if (temp_num < 7)
		{
			if (temp_num == 4)
				cout << "2" << endl;
			else if (temp_num == 5)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else
			cout << "1" << endl;
	}

	return 0;
}