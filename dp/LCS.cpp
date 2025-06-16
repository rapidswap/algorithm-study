#include <iostream>
#include <queue>
#include <tuple>   
#include <string>   
#include <algorithm>
#include <cstring>  

using namespace std;

string a, b;
int n, m;
int dp[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    n = a.size();
    m = b.size();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            dp[i][j] = max({ dp[i][j],dp[i - 1][j],dp[i][j - 1] });
        }
    }
    cout << dp[n][m];
    

   
    return 0;
}
