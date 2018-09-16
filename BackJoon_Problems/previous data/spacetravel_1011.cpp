#include <iostream>
#include <cmath>
using namespace std;

int T;
unsigned int x, y;
unsigned int dis;
unsigned int bot, top, bas, res;

int main()
{

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &x, &y);	
		dis = y - x;

		bas = (int)sqrt(dis);
		top = (bas + 1) * (bas + 1);
		bot = bas * bas;
		if (bot == dis)
			res = bas * 2 - 1;
		else if ((top - bot) / 2 >= dis - bot)
			res = bas * 2;
		else
			res = bas * 2 + 1;

		printf("%d\n", res);
	}




	return 0;
}