#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
int dp[1001];
int arr[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    sort(dp, dp + n+1);

    cout << dp[n];
    return 0;
}
