#include <iostream>
using namespace std;

int main()
{
	int comp_num = 10;
	
	int num;
	cin >> num;

	while (num > comp_num)
	{
		// float 경우 99,999,999 temp 가 2로 나온다.
		int temp = num % comp_num;
		
		num -= temp;

		if (temp >= comp_num / 2)
		{
			num += comp_num;
		}

		comp_num *= 10;
	}

	cout << num << endl;

	return 0;
}