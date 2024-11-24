#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, r;

	cin >> n >> m >> r;
	vector<int> items(n+1);
	
	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 999999999));

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				if (dist[j][i] > dist[j][k] + dist[k][i])
				{
					dist[j][i] = dist[j][k] + dist[k][i];
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 0; j <= n; j++)
		{
			if (dist[i][j] <= m)
				sum += items[j];
		}
		ans = max(ans, sum);
	}
	cout << ans;
	
	
	return 0;
}
	
