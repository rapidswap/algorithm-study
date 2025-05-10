#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_set>
using namespace std;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> answer;
    int N, M;

    cin >> N >> M;
    
    unordered_set<string> memo;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        memo.insert(str);
    }

    vector<vector<string>> blog(M);
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        istringstream iss(str);
        string token;
        while (getline(iss, token, ',')) {
            memo.erase(token);
        }
        answer.push_back(memo.size());
    }

    
    for (int n : answer) {
        cout << n << '\n';
    }
    return 0;
}
