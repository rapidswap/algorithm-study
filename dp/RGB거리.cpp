#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[1001][3];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> dp[i][j];
        }
    }
    
    for (int i = 1; i < N; i++) {
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][1], dp[i - 1][0]);
    }
    int answer = min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });
    cout << answer;

    return 0;
}
