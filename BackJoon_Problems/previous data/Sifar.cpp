#include <iostream>
using namespace std;

int main()
{
	int in_num;
	int count;
	int casenum = 1;

	cin >> in_num;

	while (in_num != 0)
	{
		int deno = 5;

		count = in_num / deno;
		deno = deno * 5;

		while (in_num >= deno)
		{
			count = count + in_num / deno;
			deno = deno * 5;
		}

		cout << "Case #" << casenum << ": " << count << endl;
		casenum += 1;

		cin >> in_num;
	}

	return 0;
}