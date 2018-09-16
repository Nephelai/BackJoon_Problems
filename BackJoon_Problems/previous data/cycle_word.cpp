#include <iostream>
#include <string.h>
using namespace std;

//백준 알고리즘 1544 문제.
//Cant Fine The reason why the answer is wrong.

struct word
{
	int length = 0;
	char content[50];
};

bool matching(word word1, word word2);

int main()
{
	int inputcase = 0;
	word dif_words[50];
	//memset(dif_words, -1, 50 * sizeof(word));
	int idx = 0;

	cin >> inputcase;
	
	for (int i = 0; i < inputcase; i++)
	{
		word tmp_word;
		//memset(words, -1, 50 * sizeof(char));
		
		cin >> tmp_word.content;

		tmp_word.length = strlen(tmp_word.content);

		if (idx == 0)
		{
			dif_words[idx] = tmp_word;
			idx++;
		}
		else
		{
			bool same = false;
			for (int j = idx - 1; j >= 0; j--)
			{
				if (matching(dif_words[j], tmp_word))
					same = true;
			}

			if (!same)
			{
				dif_words[idx] = tmp_word;
				idx++;
			}
		}
	}

	cout << idx << endl;

	return 0;
}

bool matching(word word1, word word2)
{
	if (word1.length != word2.length)
		return false;
	
	int count_word = 0;
	int idx_word[50];

	for (int i = 0; i < word2.length; i++)
	{
		if (word1.content[0] == word2.content[i])
		{
			idx_word[count_word] = i;
			count_word++;
		}
	}

	bool isMatching = true;
	if (count_word == 0)
		isMatching = false;

	for (int i = 0; i < count_word; i++)
	{
		int tmp_idx = idx_word[i];
		for (int j = 0; j < word1.length; j++)
		{
			if (tmp_idx >= word1.length)
				tmp_idx -= word1.length;
			
			if (word1.content[j] != word2.content[tmp_idx])
				isMatching = false;

			tmp_idx++;
		}
	}

	return isMatching;
}