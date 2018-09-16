#include <iostream>
using namespace std;

int testcase;
int num0;
int num1;

int Fibonacci(int n)
{
	if (n == 0)
	{
		//cout << "0" << endl;
		num0++;
		return 0;
	}

	else if (n == 1)
	{
		//cout << "1" << endl;
		num1++;
		return 0;
	}
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);

}


int main()
{
	cin >> testcase;

	int tmp;

	while (testcase != 0)
	{
		num0 = 0;
		num1 = 0;

		cin >> tmp;
		Fibonacci(tmp);

		cout << num0 << endl;
		cout << num1 << endl;

		testcase--;
	}

	return 0;
}