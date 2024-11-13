#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
bool prime(int a)
{
	if (a == 1) return false;
	if (a == 2) return true;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0) return false;
	}
	return true;
}
	
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		if (prime(i))
			cout << i << '\n';
	}
	return 0;
	
}
