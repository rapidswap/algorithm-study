#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool vist[9];
int N, M;
int arr[9];
void dfs(int n,int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!vist[i])
		{
			vist[i] = true;
			arr[cnt] = i;
			dfs(i, cnt + 1);
			vist[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	
	
	cin >> N >> M;
	
		dfs(N, 0);
	

	
	return 0;
}
	
