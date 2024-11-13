#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string order;
	cin >> order;
	
	vector<string> word;
	for (int i = 0; i < order.size(); i++)
	{
		string w;
		for (int j = i; j < order.size(); j++)
		{
			w += order[j];
		}
		word.push_back(w);
	}
	
	sort(word.begin(), word.end());
	for (string a : word)
	{
		cout << a << '\n';
	}

	return 0;
	
}
