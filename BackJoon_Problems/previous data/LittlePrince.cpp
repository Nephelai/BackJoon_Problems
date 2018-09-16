#include <iostream>
#include <cmath>
using namespace std;

int testcase;

int CheckInCircle(int x, int y, int circle[])
{
	int tmp_value = pow(x - circle[0], 2) + pow(y - circle[1], 2);
	if (tmp_value < pow(circle[2], 2))
		return 1;
	else
		return 0;
}

int main()
{
	cin >> testcase;
	
	int temp_idx = 0;
	int start_point[2];
	int end_point[2];
	int countofplanets;
	int planet_point[3];

	int isInCircle = 0;
	int totalcount = 0;

	while (testcase != 0)
	{
		while (cin >> start_point[temp_idx])
		{
			temp_idx++;
			if (temp_idx == 2)
			{
				temp_idx = 0;
				break;
			}
		}

		while (cin >> end_point[temp_idx])
		{
			temp_idx++;
			if (temp_idx == 2)
			{
				temp_idx = 0;
				break;
			}
		}

		cin >> countofplanets;

		for (int i = 0; i < countofplanets; i++)
		{
			cin >> planet_point[0];
			cin >> planet_point[1];
			cin >> planet_point[2];
			
			isInCircle += CheckInCircle(start_point[0], start_point[1], planet_point);
			isInCircle += CheckInCircle(end_point[0], end_point[1], planet_point);

			if (isInCircle == 1)
				totalcount++;

			isInCircle = 0;
		}

		cout << totalcount << endl;
		totalcount = 0;

		testcase--;
	}

	return 0;
}