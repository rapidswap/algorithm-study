#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <climits>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int>dp(N + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        int minn = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
            int tmp = i - j * j;
            minn = min(minn, dp[tmp]);
        }
        dp[i] = minn + 1;
    }
    
    cout << dp[N];
    

    return 0;
}
