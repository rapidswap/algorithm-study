#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;

long long dp[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        int n;
        cin >> n;
        for (int j = 4; j <= n; j++) {
            dp[j] = dp[j - 3] + dp[j - 2];
        }

        cout << dp[n] << '\n';
    }



    return 0;
}
