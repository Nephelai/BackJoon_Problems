#include <iostream>
using namespace std;

int NumberofCase(int num)
{
	int result = 1;

	int start = 10;
	int numberof = 2;

	num = 2 * num;

	while (start > 2)
	{
		int temp_numberof = numberof * (numberof - 1);
		int temp_res = (num - temp_numberof) % (2 * numberof);

		start = (num - temp_numberof) / (2 * numberof);

		if (temp_res == 0)
			result++;

		numberof++;
	}


	return result;
}

int main()
{
	int num;
	/*cin >> num;

	while (num != 0)
	{
		if (num == 1)
			cout << 0 << endl;
		else
			cout << NumberofCase(num) << endl;
		
		cin >> num;
	}
	*/

	for (int i = 100000; i < 1000000; i++)
	{
		cout << i << endl;
		cout << NumberofCase(i) << endl;
	}

	return 0;
}