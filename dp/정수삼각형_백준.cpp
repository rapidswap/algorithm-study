#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int tri[501][501];
int dp[501][501];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    dp[0][0] = tri[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][0] + tri[i][j];
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - 1] + tri[i][j], dp[i - 1][j] + tri[i][j]);
            }
        }
    }

    cout << *max_element(dp[n - 1], dp[n - 1] + n );

    return 0;
}
