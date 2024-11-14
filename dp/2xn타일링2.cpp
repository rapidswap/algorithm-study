#include <iostream>

using namespace std;

int dp[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
        int n;
        cin >> n;
        
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if(i%2==0)
                dp[i] = dp[i - 1]*2+1;
            else
                dp[i] = dp[i - 1] * 2 - 1;
            dp[i] %= 10007;
        }
        cout << dp[n];
 
    return 0;
}
