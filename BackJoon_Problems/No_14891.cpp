// 10:18 PM 9/28/2018
// Åé´Ï¹ÙÄû

#include <iostream>
#include <cmath>
using namespace std;

int t_num, dir, K;
bool tooth[4][8];
int pos[4];
bool state[3];

int tmp;

bool Rotatable(int a, int b) {
	int left, right;
	if (pos[a] + 2 < 8) right = pos[a] + 2;
	else right = pos[a] - 6;
	if (pos[b] - 2 >= 0) left = pos[b] - 2;
	else left = pos[b] + 6;

	if (tooth[a][right] == tooth[b][left]) return false;
	else return true;
}

void Rotate(int t, int _d) {
	if (_d == -1) {
		pos[t]++;
		if (pos[t] > 7) pos[t] = 0;
	}
	else if (_d == 1) {
		pos[t]--;
		if (pos[t] < 0) pos[t] = 7;
	}
}



int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d", &tmp);
		for (int j = 7; j >= 0; j--) {
			if (tmp % 10 == 1) tooth[i][j] = true;
			tmp /= 10;
		}
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &t_num, &dir);
		for (int t = 0; t < 3; t++) state[t] = Rotatable(t, t + 1);
		Rotate(t_num - 1, dir);
		dir *= -1;
		if (t_num == 1) {
			int t = 0;
			while (t != 3) {
				if (!state[t]) break;
				Rotate(t + 1, dir);
				dir *= -1;
				t++;
			}
		}
		else if (t_num == 2) {
			int t = 1;
			tmp = dir;
			while (t != 3) {
				if (!state[t]) break;
				Rotate(t + 1, dir);
				dir *= -1;
				t++;
			}
			t = 1;
			dir = tmp;
			while (t != 0) {
				if (!state[t - 1]) break;
				Rotate(t - 1, dir);
				dir *= -1;
				t--;
			}
		}
		else if (t_num == 3) {
			int t = 2;
			tmp = dir;
			while (t != 3) {
				if (!state[t]) break;
				Rotate(t + 1, dir);
				dir *= -1;
				t++;
			}
			t = 2;
			dir = tmp;
			while (t != 0) {
				if (!state[t - 1]) break;
				Rotate(t - 1, dir);
				dir *= -1;
				t--;
			}
		}
		else if (t_num == 4) {
			int t = 3;
			while (t != 0) {
				if (!state[t - 1]) break;
				Rotate(t - 1, dir);
				dir *= -1;
				t--;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (tooth[i][pos[i]]) res += pow(2, i);
	}
	printf("%d\n", res);


	return 0;
}