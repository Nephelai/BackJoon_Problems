#include <iostream>
using namespace std;

struct UnivData
{
	int day;
	int price;
	bool completed = false;
};

bool CheckEndSchedule(UnivData* univ, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (!univ[i].completed)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int univ_num;
	int sumofprice = 0;

	cin >> univ_num;

	UnivData* univ = new UnivData[univ_num];

	for (int i = 0; i < univ_num; i++)
	{
		cin >> univ[i].price;
		cin >> univ[i].day;
	}

	int date = 1;
	int tmp_price = 0;

	while (!CheckEndSchedule(univ, univ_num))
	{
		
		//Day 일정대로
		for (int j = 0; j < univ_num; j++)
		{
			if (!univ[j].completed)
			{
				date = univ[j].day;
				for (int i = 0; i < univ_num; i++)
				{
					if (univ[i].day == date)
					{
						univ[i].completed = true;
						if (tmp_price < univ[i].price)
							tmp_price = univ[i].price;
					}
				}
			}

			sumofprice += tmp_price;
			tmp_price = 0;
		}
	}
	
	cout << sumofprice << endl;

	return 0;
}