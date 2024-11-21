#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

//#define INF 999999999

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	vector<vector<pair<int, int>>> nodes(n+1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			nodes[i].push_back({ a,j });
			nodes[j].push_back({ a,i });
		}
	}

	bool vst[1001] = { false };
	heap.push({ 0,0 });


	long long res=0;
	while (!heap.empty())
	{
		auto node = heap.top();
		heap.pop();
		if (!vst[node.second])
		{
			vst[node.second] = true;
			res += node.first;
			for (auto a : nodes[node.second])
			{
				heap.push({ a.first,a.second });
				
			}
		}
	}
	cout << res;
	
	return 0;
}
	
