#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

bool hasCycle(bool matrix_space[60][60], int pos, int des, int size);

int main()
{
	bool matrix_space[60][60];
	memset(matrix_space, 0, 60 * 60 * sizeof(bool));

	bool wife_line[60];
	memset(wife_line, 0, 60 * sizeof(bool));

	int couple_num;
	int condition_num;

	cin >> couple_num >> condition_num;

	while (couple_num != 0)
	{
		// Set the Matrix
		for (int i = 0; i < condition_num; i++)
		{
			int first_num, second_num;
			char first_con, second_con;
			cin >> first_num >> first_con;
			cin >> second_num >> second_con;

			// set positions
			int p_start, p_end;

			// set first proposition
			if (first_con == 'h')
				p_start = first_num * 2;
			else if(first_con == 'w')
				p_start = first_num * 2 + 1;
			
			if (second_con == 'h')
				p_end = second_num * 2 + 1;
			else if (second_con == 'w')
				p_end = second_num * 2;
		
			matrix_space[p_start][p_end] = true;

			// set second proposition
			if (second_con == 'h')
				p_end = second_num * 2;
			else if (second_con == 'w')
				p_end = second_num * 2 + 1;

			if (first_con == 'h')
				p_start = first_num * 2 + 1;
			else if (first_con == 'w')
				p_start = first_num * 2;
		
			matrix_space[p_end][p_start] = true;
		}

		// Searching Graph
		// If 'kh' start 'kw' end
		// this 'kh' is Position in '0w' Line
		// Has Route of 'kh' start 'kw' end and 'kw' start 'kh' end, Has Cycle
		// call 'bad luck'
		// If Perfect Cycle is Dont Care

		stack<int> fixed_wifeline;
		stack<int> trace_stack;

		for (int x = 0; x < couple_num * 2; x++)
		{
			for (int y = 0; y < couple_num * 2; y++)
			{
				bool tmp_countinue;
				tmp_countinue = matrix_space[x][y];

				// Fixed wife_line number
				if (tmp_countinue)
				{
					trace_stack.push(y);

					int desti = x;
					if (desti % 2 == 0)
						desti += 1;
					else
						desti -= 1;

					int tmp_pos;
					bool first_loop = true;

					while (!trace_stack.empty())
					{
						tmp_pos = trace_stack.top();
						trace_stack.pop();

						for (int i = 0; i < couple_num * 2; i++)
						{
							if (matrix_space[tmp_pos][i])
								trace_stack.push(i);
						}

						if (!first_loop)
						{
							if (tmp_pos == desti)
							{
								wife_line[x] = true;
								fixed_wifeline.push(x);
							}
							else if (tmp_pos == x)
							{
								while (!trace_stack.empty())
									trace_stack.pop();
							}
						}

						first_loop = false;
					}
					
				}
			}
		}

		bool badluck = false;
		for (int i = 1; i < couple_num; i++)
		{
			if (wife_line[i * 2] && wife_line[i * 2 + 1])
			{
				while (!fixed_wifeline.empty())
					fixed_wifeline.pop();
				cout << "bad luck" << endl;
				badluck = true;
				break;
			}
		}

		// Arrange the Line
		while (!fixed_wifeline.empty())
		{
			int tmp_val = fixed_wifeline.top();
			fixed_wifeline.pop();

			while (!fixed_wifeline.empty() && tmp_val == fixed_wifeline.top())
			{
				fixed_wifeline.pop();
			}
			
			int checked_val = tmp_val / 2;
			checked_val *= 2;

			if (!wife_line[checked_val] && !wife_line[checked_val + 1])
			{
				wife_line[tmp_val] = true;
			}

			for (int i = 0; i < couple_num * 2; i++)
			{
				if (matrix_space[tmp_val][i])
					fixed_wifeline.push(i);
			}

		}

		if (!badluck)
		{
			for (int i = 1; i < couple_num; i++)
			{
				if (wife_line[i * 2 + 1])
					cout << i << "w ";
				else
					cout << i << "h ";
			}
			cout << endl;
		}
		
		// Initialize
		memset(matrix_space, 0, 60 * 60 * sizeof(bool));
		memset(wife_line, 0, 60 * sizeof(bool));
		cin >> couple_num >> condition_num;
	}

	return 0;
}

bool hasCycle(bool matrix_space[60][60], int pos, int des, int size)
{
	// set destination
	if (des % 2 == 0)
		des = des + 1;
	else
		des = des - 1;

	stack<int> trace_stack;
	trace_stack.push(pos);

	int tmp_pos;
	bool first_loop = true;

	while (!trace_stack.empty())
	{
		tmp_pos = trace_stack.top();
		trace_stack.pop();

		if (!first_loop)
		{
			if (tmp_pos == des)
				return true;
			else if (tmp_pos == pos)
				return false;
		}
	
		for (int i = 0; i < size; i++)
		{
			if (matrix_space[tmp_pos][i])
				trace_stack.push(i);
		}

		first_loop = false;
	}

	return false;
}