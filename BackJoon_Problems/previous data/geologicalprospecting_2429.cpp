#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int width, height, points, range;
	cin >> width;
	cin >> height;
	cin >> points;
	cin >> range;

	height++;
	width++;

	int** space = new int*[width];
	for (int i = 0; i < width; i++)
	{
		space[i] = new int[height];
		memset(space[i], 0, sizeof(int) * height);
	}

	for (int i = 0; i < points; i++)
	{
		int x, y;
		cin >> x >> y;
		space[x][y] = 1;
	}

	int tmp_count = 0;
	int max_count = 0;
	int pos_x = 0;
	int pos_y = 0;

	for (int x = 0; x < width - range; x++)
	{
		for (int y = 0; y < height - range; y++)
		{
			for (int tmp_x = x; tmp_x <= x + range; tmp_x++)
			{
				for (int tmp_y = y; tmp_y <= y + range; tmp_y++)
				{
					if (space[tmp_x][tmp_y] == 1)
						tmp_count++;
				}
			}

			if (max_count < tmp_count)
			{
				max_count = tmp_count;
				pos_x = x;
				pos_y = y;
			}
				
			tmp_count = 0;
		}
	}


	cout << pos_x << ' ' << pos_y << endl;
	cout << max_count << endl;

	return 0;
}