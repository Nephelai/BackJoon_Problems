#include <iostream>
using namespace std;

//2차 배열의 경우도 괞찮다고 생각

class Node
{
private:
	int value;
	int count;

	Node* nextnodes[1000];

public:
	int index;
	bool isHead;
	
	Node();
	void setValue(int val);
	void setNextNode(Node* tmp_node);
	int getCount();

	Node* TraversalNode(Node* begin_node,int idx, int tmptime);
};

int testcase = 0;
//int total_time = 0;
int t_arry[1000];
int tmp_idx = 0;

void StoreTime(int _time)
{
	t_arry[tmp_idx] = _time;
	tmp_idx++;
}

int main()
{
	cin >> testcase;

	while (testcase != 0)
	{
		memset(t_arry, 0, 4000);
		int c_node;
		int c_condi;

		cin >> c_node;
		cin >> c_condi;

		Node* whole = new Node[c_node];

		for (int i = 0; i < c_node; i++)
		{
			int tmp_val;
			cin >> tmp_val;
			whole[i].setValue(tmp_val);
			whole[i].index = i;
		}

		for (int i = 0; i < c_condi; i++)
		{
			int front_node;
			int back_node;

			cin >> front_node;
			cin >> back_node;

			whole[front_node - 1].setNextNode(&whole[back_node - 1]);
			whole[back_node - 1].isHead = false;
		}	

		int desti;

		cin >> desti;

		for (int i = 0; i < c_node; i++)
		{
			if (whole[i].isHead)
			{
				//int tmptime = 0;
				whole[i].TraversalNode(&whole[i], desti - 1, 0);
			}
		}

		int totaltime = 0;
		for (int i = 0; i < 1000; i++)
		{
			if (t_arry[i] == 0)
				break;
			else if(totaltime < t_arry[i])
				totaltime = t_arry[i];
		}

		cout << totaltime << endl;

		tmp_idx = 0;
		delete[] whole;

		testcase--;
	}

	return 0;
}

Node::Node()
{
	isHead = true;
	value = -1;
	memset(nextnodes, NULL, 4000);
	count = 0;
}

void Node::setValue(int val)
{
	value = val;
}

void Node::setNextNode(Node* tmp_node)
{
	int tmp = 0;
	while (nextnodes[tmp] != NULL)
		tmp++;
	nextnodes[tmp] = tmp_node;
	count++;
}

Node* Node::TraversalNode(Node* begin_node, int idx, int tmptime)
{
	int tmp_count = begin_node->getCount();
	tmptime += begin_node->value;
	//total_time += begin_node->value;
	if (begin_node->index == idx)
	{
		StoreTime(tmptime);
		return NULL;
	}
		
	// while 이나 for 문이 깨져버린다.


	else if (tmp_count != 0)
	{
		for (int i = 0; i < tmp_count; i++)
		{
			TraversalNode(begin_node->nextnodes[i], idx, tmptime);
		}
	}

	return NULL;
	
	/*else
	{
		total_time -= begin_node->value;
		return NULL;
	}*/
	
}

int Node::getCount()
{
	return count;
}