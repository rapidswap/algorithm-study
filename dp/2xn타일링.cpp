#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int dp[1001];
	dp[1] = 1;
	dp[2] = 2;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1])%10007;
	}
	cout << dp[n];
	
	
	
	return 0;
}
	
