#include <iostream>
using namespace std;

int main()
{
	int w_univ[3] = { 0 };
	int k_univ[3] = { 0 };
	int temp_score;

	for (int i = 0; i < 10; i++)
	{
		cin >> temp_score;

		if (i < 2)
		{
			w_univ[i] = temp_score;
		}
		else
		{
			if (w_univ[2] < temp_score)
			{
				//update
				w_univ[2] = temp_score;

				//re_arrange
				if (w_univ[0] < w_univ[1])
				{
					int tmp = w_univ[0];
					w_univ[0] = w_univ[1];
					w_univ[1] = tmp;
				}

				if (w_univ[1] < w_univ[2])
				{
					int tmp = w_univ[1];
					w_univ[1] = w_univ[2];
					w_univ[2] = tmp;
				}

				if (w_univ[0] < w_univ[1])
				{
					int tmp = w_univ[0];
					w_univ[0] = w_univ[1];
					w_univ[1] = tmp;
				}
			}
		}
	}
		
	
	for (int i = 0; i < 10; i++)
	{
		cin >> temp_score;

		if (i < 2)
		{
			k_univ[i] = temp_score;
		}
		else
		{
			if (k_univ[2] < temp_score)
			{
				//update
				k_univ[2] = temp_score;

				//re_arrange
				if (k_univ[0] < k_univ[1])
				{
					int tmp = k_univ[0];
					k_univ[0] = k_univ[1];
					k_univ[1] = tmp;
				}

				if (k_univ[1] < k_univ[2])
				{
					int tmp = k_univ[1];
					k_univ[1] = k_univ[2];
					k_univ[2] = tmp;
				}

				if (k_univ[0] < k_univ[1])
				{
					int tmp = k_univ[0];
					k_univ[0] = k_univ[1];
					k_univ[1] = tmp;
				}
			}
		}
	}

	cout << w_univ[0] + w_univ[1] + w_univ[2] << ' ' << k_univ[0] + k_univ[1] + k_univ[2] << endl;


	return 0;
}