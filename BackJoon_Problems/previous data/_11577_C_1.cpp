#include <iostream>
using namespace std;

bool turned[100004] = { false };
bool check = { false };
int idx;
int light_size;
int remote_size;
int tmp;
int remote_cnt;

int ChangeLight(int pt) {
	if (pt + remote_size > light_size)
		return pt;

	for (int i = pt; i < pt + remote_size; i++) {
		if (turned[i])
			turned[i] = false;
		else
			turned[i] = true;
	}
	return 0;
}

int main()
{
	cin.tie(NULL);
	scanf("%d%d", &light_size, &remote_size);
	for (int i = 0; i < light_size; i++) {
		scanf("%d", &tmp);
		if (tmp == 1)
			turned[i] = true;
	}

	for (int i = 0; i < light_size; i++) {
		if (turned[i] == true) {
			idx = ChangeLight(i);
			remote_cnt++;
		}
	}

	for (int i = idx; i < light_size; i++) {
		if (turned[i])
			check = true;
	}

	if (check)
		printf("Insomnia\n");
	else
		printf("%d\n", remote_cnt);

	return 0;
}