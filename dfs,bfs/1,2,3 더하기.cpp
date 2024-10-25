#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer;
int cnt = 0;

void dfs(int target, int sum) {
	if (target == sum) {
		cnt++;
		return;
	}
	else if (target < sum) {
		return;
	}
	dfs(target, sum + 1);
	dfs(target, sum + 2);
	dfs(target, sum + 3);
}

int main() {
	int n;
	cin >> n;
	vector<int>numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < n; i++) {
		dfs(numbers[i], 0);
		answer.push_back(cnt);
		cnt = 0;
	}
	for (int str : answer) {
		cout << str<<endl;
	}
	
}
