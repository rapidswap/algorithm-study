#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 110
int n, m;
int W[MAX];
int V[MAX];
int DP[MAX][100010];
int dp[101][100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= n; i++) {                   
        for (int j = 1; j <= m; j++) {               
            if (j >= W[i]) {                          
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);  
            }
            else DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[n][m] << endl;
    return 0;
}
