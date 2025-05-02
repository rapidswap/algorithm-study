#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lamb_cnt,bridge_len;

bool check_light(int height,vector<int> pos) {
	for (int i = 0; i < lamb_cnt; i++) {
		if (i == 0) {
			if (pos[i] - height > 0) return false;
		}
		
		if (pos[i] - height > pos[i - 1] + height) {
			return false;
		}
		if (lamb_cnt - 1 == i) {
			if (pos[i] + height < bridge_len) return false;
		}
		
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	vector<int> position;
	cin >> N;
	cin >> M;
	lamb_cnt = M;
	bridge_len = N;
	int answer = 1;

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		position.push_back(a);
	}

	int st, ed;
	int mid;
	st = 1;
	ed = N;
	int result=0;
	while (st <= ed) {
		mid = (st + ed) / 2;
		if (check_light(mid, position)) {
			result = mid;
			ed = mid-1;
		}
		else {
			st = mid + 1;
		}
	}

	cout << result;
}
