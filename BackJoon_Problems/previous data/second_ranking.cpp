#include <iostream>
#include <algorithm>
using namespace std;

struct Table
{
	int *table;
	int *count;
	int size = 0;
};

int main()
{
	while (true)
	{
		int weeks;
		int h_ranks;

		cin >> weeks;
		cin >> h_ranks;

		if (weeks == 0 && h_ranks == 0)
			return 0;

		Table result;
		result.table = new int[weeks * h_ranks];
		result.count = new int[weeks * h_ranks];

		int tmp_num;
		int dif_num;

		for (int x = 0; x < weeks; x++)
		{
			for (int y = 0; y < h_ranks; y++)
			{
				cin >> tmp_num;

				//tmp_same = false;
				dif_num = 0;
				for (int idx = 0; idx < result.size; idx++)
				{
					if (result.table[idx] == tmp_num)
					{
						result.count[idx]++;
					}
					else
					{
						dif_num++;
					}
				}

				if (dif_num == result.size)
				{
					result.table[result.size] = tmp_num;
					result.count[result.size] = 1;
					result.size++;
				}

			}
		}

		int first_num = 0;
		int second_num = 0;

		for (int i = 0; i < result.size; i++)
		{
			if (result.count[i] > first_num)
				first_num = result.count[i];
			else if (result.count[i] > second_num)
				second_num = result.count[i];
		}

		int *result_array = new int[result.size];
		int count = 0;

		for (int i = 0; i < result.size; i++)
		{
			if (result.count[i] == second_num)
			{
				result_array[count] = result.table[i];
				count++;
			}
		}

		sort(result_array, result_array + count);

		for (int i = 0; i < count; i++)
		{
			cout << result_array[i] << " ";
		}

		cout << endl;


		delete[] result_array;
		delete[] result.table;
	}

	return 0;
}