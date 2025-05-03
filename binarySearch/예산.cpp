#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int st, ed, mid;
int goverment;
bool check_money(vector<int> v, int money) {
	int all=0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]<money) {
			all += v[i];
		}
		else {
			all += money;
		}
	}
	return all <= goverment;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	vector<int> budget;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		budget.push_back(a);
	}


	cin >> goverment;

	st = 1;
	ed = *max_element(budget.begin(),budget.end());
	int res = 0;

	while (st <= ed) {

		mid = (st + ed) / 2;

		if (check_money(budget, mid)) {
			st = mid+1;
			res = mid;
		}
		else {
			ed = mid-1;
		}
	}
	cout << res;

	


	
}
