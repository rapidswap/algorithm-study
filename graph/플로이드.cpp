#include<iostream>
#include<queue>
#include<vector>
using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	
	cin >> n >> m;
	vector<vector<int>> result(n+1,vector<int>(n+1,999999999));

	for (int i = 1; i <= n; i++)
	{
		result[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		result[a][b] = min(c, result[a][b]);
	}

	for (int k = 1; k <= n; k++) //거치는
	{
		for (int j = 1; j <= n; j++)//시작
		{
			for (int i = 1; i <= n; i++)//도착
			{
				if (result[j][i] > result[j][k] + result[k][i])
				{
					result[j][i] = result[j][k] + result[k][i];
				}
			}
		}
	}

	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (result[j][i] == 999999999) cout << 0 << " ";
			else
				cout << result[j][i] << " ";
		}
		cout << '\n';
	}

	
	return 0;
}
	
