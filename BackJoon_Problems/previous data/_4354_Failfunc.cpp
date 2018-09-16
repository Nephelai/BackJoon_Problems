#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int fail[1000001];
int tmp_m, m;


int main()
{
	// fail func ¸¸µé±â
	
	while (true) {
		m = 1;
		tmp_m = 1;
		getline(cin, str);
		for (int i = 1, j = 0; i < str.length(); i++) {
			while (j > 0 && str[i] != str[j]) {
				j = fail[j - 1];
				tmp_m = fail[j - 1];
			}
			if (str[i] == str[j]) {
				fail[i] = ++j;
				++tmp_m;
			}
			if (tmp_m > m)
				m = tmp_m;
		}

		cout << m << endl;
	}

	


	return 0;
}