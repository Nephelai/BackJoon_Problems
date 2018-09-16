// 유레카 이론
// 오후 7:59 2018-09-11 오후 9:15 2018-09-11

#include<iostream>
using namespace std;

int triangles[46];
bool pos[4000];

int testcase;
int tmp;

int main() {

	for (int i = 1; i <= 45; i++)  triangles[i] = (i * (i + 1)) / 2;

	for (int i = 1; i <= 45; i++)
		for (int j = 1; j <= 45; j++)
			for (int k = 1; k <= 45; k++)
				pos[triangles[i] + triangles[j] + triangles[k]] = true;

	scanf("%d", &testcase);
	while (testcase--)	{
		scanf("%d", &tmp);
		if (pos[tmp]) printf("1\n");
		else printf("0\n");
	}


	return 0;
}