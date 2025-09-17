#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> rank(N);
    for (int i = 0; i < N; i++) {
        cin >> rank[i];
    }

    sort(rank.begin(), rank.end());

    ll answer = 0;
    for (int i = 0; i < N; i++) {
        answer += abs((i + 1)-rank[i]);
    }
    cout << answer;
    return 0;
}
