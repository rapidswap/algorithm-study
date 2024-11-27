#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<cmath>
#include <limits.h>
using namespace std;

int n;
int getMin = INT_MAX;
int getMax = INT_MIN;
vector<int> num;

void findMinMax(vector<int> &nums, int idx, int result, int add, int sub, int mul, int div)
{
	if (idx == n - 1)
	{
		getMin = min(getMin, result);
		getMax = max(getMax, result);
		return;
	}
	if (add > 0)
	{
		findMinMax(nums, idx+1, result + nums[idx+1],add - 1, sub, mul, div);
		
	}
	if (sub > 0)
	{
		findMinMax(nums,idx+1,result-nums[idx+1], add, sub-1, mul, div);
	}
	if (mul > 0)
	{
		findMinMax(nums,idx+1,result*nums[idx+1],add, sub, mul-1, div);
	}
	if (div > 0)
	{
		findMinMax(nums,idx+1,result/nums[idx+1], add, sub, mul, div-1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n;
	
	num.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	
	int addtion, subtraction, division, multiplication;
	cin >> addtion >> subtraction >> multiplication >> division;

	findMinMax(num, 0, num[0], addtion, subtraction, multiplication, division);
	cout << getMax << '\n';
	cout << getMin << "\n";

	
	return 0;
}
	
