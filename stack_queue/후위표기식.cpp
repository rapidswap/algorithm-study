#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string order;
	
	cin >> order;

	queue<char> q;
	stack<char> stk;
	for (int i = 0; i < order.size(); i++)
	{
		if (isalpha(order[i]))
			cout << order[i];
		else
		{
			if (order[i] == '(')
			{
				stk.push(order[i]);
			}
			else if (order[i] == '*' || order[i] == '/')
			{
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
				{
					cout << stk.top();
					stk.pop();
				}
				stk.push(order[i]);
			}
			else if (order[i] == '+' || order[i] == '-')
			{
				while (!stk.empty() && stk.top()!='(')
				{
					cout << stk.top();
					stk.pop();
				}
				stk.push(order[i]);
			}
			else if (order[i] == ')')
			{
				while (!stk.empty() && stk.top() != '(')
				{
					cout << stk.top();
					stk.pop();
				}
				stk.pop();
			}
		}
	}
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
	return 0;
}//https://donggoolosori.github.io/2020/10/19/boj-1918/
