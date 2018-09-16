#include <iostream>
#include <string>
using namespace std;

int main()
{
	for (int i = 0; i < 100; i++)
	{
		string sentence;
		getline(cin, sentence);

		cout << sentence << endl;
	}
	
	return 0;
}