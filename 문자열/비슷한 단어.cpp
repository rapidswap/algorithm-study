#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;

	vector<string> words(N);

	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		words[i] = a;
	}
	
	map<char, int> cm;
	vector<char> comStr;
	for (char c : words[0]) {
		comStr.push_back(c);
		cm[c]++;
	}


	int answer = 0;
	for (int i = 1; i < words.size(); i++) {
		vector<char> str;
		if (words[i].size() > comStr.size()+1) continue;
		if (words[i].size() < comStr.size() - 1) continue;
		map<char, int> sm;
		for (char c : words[i]) {
			str.push_back(c);
			sm[c]++;
		}
		
		int firstplusComCnt = 0;
		int firstminusComCnt = 0;
		int comCnt = 0;
		for (auto c : sm) {
			if (cm[c.first] > sm[c.first]) {
				firstminusComCnt += cm[c.first] - sm[c.first];

			}
			else
				firstplusComCnt += sm[c.first] - cm[c.first];

			if (firstminusComCnt < -1) {
				comCnt = -1;
				break;
			}
			if (firstplusComCnt > 1) {
				comCnt = -1;
				break;
			}
		}

		int secondplusComCnt = 0;
		int secondminusComCnt = 0;
		for (auto c:cm) {
			if (sm[c.first] > cm[c.first]) {
				secondminusComCnt += sm[c.first] - cm[c.first];

			}
			else
				secondplusComCnt += cm[c.first] - sm[c.first];
			if (secondminusComCnt < -1) {
				comCnt = -1;
				break;
			}
			if (secondplusComCnt > 1) {
				comCnt = -1;
				break;
			}

		}
		if (comCnt == 0) {
			answer++;
		}

	}
	
	cout << answer;

	return 0;
}
