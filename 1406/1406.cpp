#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

stack<char> st1, st2;

int main()
{
	char a = 'a';
	char c, d;
	char temp;
	int b;

	while (1)
	{
		a = getchar();
		if (a == '\n') break;
		st1.push(a);
	}
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cin >> c;
		if (c == 'P')
		{
			cin >> d;
			st1.push(d);
		}
		else if (c == 'B')
		{
			if (!st1.empty())
				st1.pop();
		}
		else if (c == 'L')
		{
			if (!st1.empty())
			{
				temp = st1.top();
				st1.pop();
				st2.push(temp);
			}
		}
		else if (c == 'D')
		{
			if (!st2.empty())
			{
				temp = st2.top();
				st2.pop();
				st1.push(temp);
			}
		}
	}
	while (!st1.empty())
	{
		st2.push(st1.top());
		st1.pop();
	}
	while (!st2.empty())
	{
		printf("%c", st2.top()); st2.pop();
	}
	return 0;
}