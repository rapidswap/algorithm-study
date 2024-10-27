#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int main() {
	int n, m;
	int answer=0;
	vector<int> sortNum;
	vector<int> sunseo;
	cin >> n >> m;
	

	vector<vector<int>> Apt(m);
	for (int i = 0; i < m; i++) {
		int one;
		int two;
		cin >> one >> two;
		Apt[i].push_back(one);
		Apt[i].push_back(two);
	}
	for (int i = 0; i < m; i++) {
		for (int num : Apt[i]) {
			sortNum.push_back(num);
		}
	}
	sort(sortNum.begin(), sortNum.end());

	for (int i = 0; i < sortNum.size(); i++) {
		for (int j = 0; j < m; j++) {
			if (sortNum[i] == Apt[j][0] || sortNum[i] == Apt[j][1]) {
				sunseo.push_back(j);
			}
		}
	}
	int cnt = 0;
	int idx = 0;
	while (cnt != n) {
		cnt++;
		if (cnt != n) idx++;
		if (idx == sortNum.size()) idx = 0;
		
	}
	

	cout << sunseo[idx]+1;

	return 0;
	

}
