#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> stair;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        stair.push_back(a);
    }
    if (N == 1) {
        cout << stair[0];
        return 0;
    }

    vector<vector<int>> dp(N, vector<int>(2));

    dp[0][0] = stair[0];
    dp[0][1] = 0;
    dp[1][0] = stair[1];
    dp[1][1] = stair[0] + stair[1];

    for (int i = 2; i < N; i++) {
        dp[i][0] = max(dp[i - 2][1], dp[i - 2][0]) + stair[i];
        dp[i][1] = dp[i - 1][0] + stair[i];
    }
    cout << max(dp[N - 1][0], dp[N - 1][1]);
    return 0;
}
