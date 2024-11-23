#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 999999999

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	int N, M;
	
	cin >> N >> M;
	vector<long long> trees(N);
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
	}

	long long treeMax = *max_element(trees.begin(), trees.end());
	long long st = 1;
	long long ed = treeMax;

	long long res = 0;
	while (st <= ed)
	{
		long long total = 0;
		long long mid = (st + ed) / 2;
		for (int i = 0; i < N; i++)
		{
			if((trees[i]-mid)>0)
				total += trees[i] - mid;
		}
		if (total >= M)
		{
			res = mid;
			st = mid + 1;
		}
		if (total < M)
		{
			ed = mid - 1;
		}

	}
	cout << res;

	
	return 0;
}
	
