#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int> &b) {

	if (a.second != b.second) {
		return a.second > b.second;
	}
	if (a.first.size() != b.first.size()) {
		return a.first.size() > b.first.size();
	}
	return a.first < b.first;
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_map<string, int> words;

	int N, M;
	cin >> N; cin >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		words[str]++;
	}

	vector<pair<string,int>> v(words.begin(), words.end());
	sort(v.begin(), v.end(), cmp);

	for (auto w : v) {
		if(w.first.size()>=M)
			cout << w.first << '\n';
	}
	
}
