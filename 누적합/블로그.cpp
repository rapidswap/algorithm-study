#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include<numeric>
using namespace std;

int main()
{
	int N,X;
	cin >> N >> X;
	
	vector<int> blog(N);
	int sum = 0;
	for (int i = 0; i < X; i++)
	{
		cin >> blog[i];
		sum += blog[i];
	}

	int answer = sum;
	int cnt = 1;
	for (int i = X; i < N; i++)
	{
		cin >> blog[i];
		sum += blog[i] - blog[i - X];

		if (sum >= answer)
		{
			if (sum == answer)
			{
				cnt++;
			}
			else
			{
				answer = sum;
				cnt = 1;
			}
		}
	}
	
	if (answer == 0)
		cout << "SAD";
	else
	{
		cout << answer << '\n' << cnt;
	}
	return 0;
}
