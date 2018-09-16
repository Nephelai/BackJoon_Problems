#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int univ_num;
	cin >> univ_num;
	
	//int* schedule = new int[univ_num];
	//memset(schedule, 0, sizeof(int) * univ_num);
	int schedule[10000] = { 0 };

	for (int i = 0; i < univ_num; i++)
	{
		int temp_price;
		int temp_day;

		int remain_price;

		cin >> temp_price;
		cin >> temp_day;

		if (schedule[temp_day - 1] == 0)
		{
			schedule[temp_day - 1] = temp_price;
		}
		else if (schedule[temp_day - 1] < temp_price)
		{
			remain_price = schedule[temp_day - 1];
			schedule[temp_day - 1] = temp_price;
			// check rest array
			for (int i = temp_day - 2; i >= 0; i--)
			{
				if (schedule[i] == 0)
				{
					schedule[i] = remain_price;
					break;
				}
				else if (schedule[i] < remain_price)
				{
					int tmp_price = schedule[i];
					schedule[i] = remain_price;
					remain_price = tmp_price;
				}
			}
		}
		else
		{
			remain_price = temp_price;
			for (int i = temp_day - 2; i >= 0; i--)
			{
				if (schedule[i] == 0)
				{
					schedule[i] = remain_price;
					break;
				}
				else if (schedule[i] < remain_price)
				{
					int tmp_price = schedule[i];
					schedule[i] = remain_price;
					remain_price = tmp_price;
				}
			}
		}
	}

	int sumofprice = 0;
	for (int i = 0; i < 10000; i++)
	{
		sumofprice += schedule[i];
	}

	cout << sumofprice << endl;

	return 0;
}