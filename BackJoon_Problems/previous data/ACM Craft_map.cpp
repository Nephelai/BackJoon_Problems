#include <iostream>
#include <map>
using namespace std;

int testcase = 0;


// Not Finished!!
int main()
{
	cin >> testcase;

	while (testcase != 0)
	{
		int c_node;
		int c_condi;

		cin >> c_node;
		cin >> c_condi;

		map<int, int> t_map;

		for (int i = 1; i <= c_node; i++)
		{
			int tmp_val;
			cin >> tmp_val;
			t_map.insert(map<int, int>::value_type(i, tmp_val));
		}

		for (int i = 0; i < c_condi; i++)
		{
			int front_node;
			int back_node;

			cin >> front_node;
			cin >> back_node;

			whole[front_node - 1].setNextNode(&whole[back_node - 1]);
			//whole[back_node - 1].isHead = false;
		}

		int desti;

		cin >> desti;

		int total_time = 0;

		for (int i = 0; i < c_node; i++)
		{
			if (whole[i].isHead)
			{
				int tmp_count = whole[i].getCount();
				int idx = i;
				whole[idx].getCount

			}
		}


		testcase--;
	}

	return 0;
}