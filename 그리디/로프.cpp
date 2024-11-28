#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include <limits.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> lines(n);
	for (int i = 0; i < n; i++)
	{
		cin >> lines[i];
	}
	sort(lines.begin(), lines.end());
	int getMax = INT_MIN;
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i] == 0) continue;
		int a = lines[i] * (n - i);
		getMax = max(getMax, a);
	}
	cout << getMax;
	return 0;
}
	
