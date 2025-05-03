#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N,K;
	cin >> N>>K;
	string str;
	int cnt = 0;
	cin >> str;

	for (int i = 0; i < N; i++) {
		if (str[i] == 'P') {
			for (int j = i - K; j <= i + K; j++) {
				if (j >= 0 && j < N && str[j] == 'H') {
					str[j] = 'C';
					cnt++;
					break;
				}
			}
		}
		else continue;
	}

	cout << cnt;
	return 0;
}
