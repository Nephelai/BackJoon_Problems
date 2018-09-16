#include <stdio.h>

int T;
int a, b;
int tmp_c;

int main() {


	scanf("%d", &T);
	while (T--)	{
		scanf("%d%d", &a, &b);
		b = b % 26;
		a = a % 26;

		while (getchar() != '\n');
		while (tmp_c = getchar()) {
			if (tmp_c < 65 || tmp_c > 91)
				break;
			tmp_c -= 65;
			tmp_c *= a;
			tmp_c += b;
			tmp_c %= 26;
			
			tmp_c += 65;
			printf("%c", tmp_c);
		}
		printf("\n");
	}

	return 0;
}