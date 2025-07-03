#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int bag[101][2];
int dp[100001][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> bag[i][0];
        cin >> bag[i][1];
    }

    for (int i = 1; i <= n; i++) {

    }
    
    return 0;
}
