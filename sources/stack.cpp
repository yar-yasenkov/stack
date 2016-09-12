// stack.cpp : Defines the entry point for the console application.


//#include "stdafx.h"
#include "Stack.h"
#include <iostream>

using namespace std;
/*int _tmain(int argc, _TCHAR* argv[])
{
	char comm[6];
	char push[6] = "push";
	char pop[6] = "pop";
	char count[6] = "count";
	char stop[6] = "stop";
	stack<int> st;
	int num = 0;
	int top_value;
	cout << "commands" << endl;	
	do
	{
		cin >> comm;
		if (!strcmp(comm, push))
		{
			cout << "enter number" << endl;
			cin >> num;
			st.push(num);
		}
		if (!strcmp(comm, pop))
		{
			try
			{
				top_value = st.pop();
				cout << top_value << endl;
			}
			catch (char *s)
			{
				cout << s << endl;
			}
		}
		if (!strcmp(comm, count))
		{
			cout << st.count() << endl;
		}

	} while (strcmp(comm, stop));
	system("pause");
	return 0;
}

*/
