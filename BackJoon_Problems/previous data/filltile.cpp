#include <iostream>
#include <cmath>
using namespace std;

int dp[15];

int main()
{
	int tile;
	cin >> tile;
	
	tile /= 2;
	int result = 0;
	int count = 1;
	int index = 1;
	int n;
	dp[0] = 3;

	for (int i = 1; i < tile; i++)
	{
		for (int p = 0; p < index; p++)
		{
			dp[p] *= 3;
			if (p != 0) {
				if (p == 1) { n = i - 1; }
				dp[p] *= (n + p);
				dp[p] /= n;
				n -= 2;
			}
		}
		if (i % 2 != 0) {
			dp[index] = pow(2, index);
			index++;
		}
	}

	for (int i = 0; i < index; i++)
	{
		result += dp[i];
	}

	cout << result << endl;

	return 0;
}