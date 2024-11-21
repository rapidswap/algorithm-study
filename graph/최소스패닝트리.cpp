#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//프림알고리즘

bool vist[100001] = { false };

int main()
{
	int v, e;
	cin >> v >> e;
	vector<vector<pair<int, int>>>nodes(v+1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	for (int i = 1; i <= e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({ c,b });
		nodes[b].push_back({ c,a });
	}

	heap.push({ 0,1 });
	int answer = 0;
	while (!heap.empty())
	{
		auto node = heap.top();
		heap.pop();
		if (!vist[node.second])
		{
			answer += node.first;
			vist[node.second] = true;
			for (auto a : nodes[node.second])
			{
				heap.push({ a.first,a.second });
			}

		}
	}
	cout << answer;

}
