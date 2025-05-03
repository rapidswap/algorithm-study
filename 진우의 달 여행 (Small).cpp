#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int cost = 0;
int minCost = INT_MAX;
int N, M;
vector<vector<int>> space;

void dfs(int level,int idx,int cost,int prevMv) {

	if (level == N) {
		minCost = min(minCost, cost);
		return;
	}

	for (int nextMv = 0; nextMv < 3; nextMv++) {
		if (nextMv == prevMv) continue;
		
		int nextIdx;
		switch (nextMv) {
		case 0:
			nextIdx= idx-1;
			break;
		case 1:
			nextIdx = idx;
			break;
		case 2:
			nextIdx =idx + 1;
			break;
		}

		if (nextIdx >= 0 && nextIdx < M) {
			dfs(level + 1, nextIdx, cost + space[level][nextIdx], nextMv);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	space.resize(N, vector<int>(M));

	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			space[i][j] = a;
		}
	}
	for (int i = 0; i < M; i++) {
		
		dfs(1, i, space[0][i],-1);
	}

	cout << minCost;
	return 0;
}
