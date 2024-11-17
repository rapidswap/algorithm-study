#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> points;
	
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	sort(points.begin(), points.end(),cmp);
	for (auto a : points)
	{
		cout << a.first << ' ' << a.second << '\n';
	}
	

}
