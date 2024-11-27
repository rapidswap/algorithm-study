#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<pair<int,int>> stk;
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		while (!stk.empty())
		{
			if (stk.top().second > a)
			{
				cout << stk.top().first << " ";
				break;
			}
			else
			{
				stk.pop();
			}
		}
		if (stk.empty())
		{
			cout << 0 << " ";
		}
		stk.push({ i,a });
	}
	
	
	
	return 0;
}
	
