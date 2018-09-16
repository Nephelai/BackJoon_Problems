#include <iostream>
#include <list>
using namespace std;

void ChecktheList(list<pair<int, int>> &route)
{
	route.sort();
	//pair<int, int> _temp = route.pop_back();
	list<pair<int, int>>::iterator iter;
	list<pair<int, int>>::iterator next_iter;
	//_temp 
	for (iter = route.begin(); iter != route.end(); ++iter)
	{
		
		next_iter = iter;
		next_iter++;

		if (iter->second >= next_iter->first)
		{
			pair<int, int> tmp_p = { next_iter->first, next_iter->second };
			iter->second = next_iter->second;
			route.remove(tmp_p);
		}
	}
}

int main()
{
	int num_case, fin_des;

	cin >> num_case >> fin_des;

	int start, end;

	//pair<int, int>* route = new pair<int, int>[num_case];
	list<pair<int, int>> route;
	list<pair<int, int>>::iterator iter;

	for (int i = 0; i < num_case; i++)
	{
		cin >> start >> end;
		
		pair<int, int> tmp_distance;
		tmp_distance.first = start;
		tmp_distance.second = end;
		if (i == 0)
			route.push_back(tmp_distance);
		else
		{
			if (start <= end)
			{
				// nothing to do
				// check the list
				for (iter = route.begin(); iter != route.end(); ++iter)
				{
					if (start <= iter->first)
					{
						if (end <= iter->first)
						{
							route.push_back(tmp_distance);
							iter++;
							// Must Check the list
							ChecktheList(route);
						}
						else
						{
							// Chage the first
							iter->first = start;
						}
					}
					else
					{
						if (end >= iter->second)
						{
							// Chage the end
							iter->second = end;
						}
						else
						{
							route.push_back(tmp_distance);
							iter++;
							// Must Check the list
							ChecktheList(route);
						}
					}
				}
			}
			else
			{

			}
		}
	}


	return 0;
}