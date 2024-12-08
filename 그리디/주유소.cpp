#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include<numeric>
using namespace std;

int main()
{
	int N;
	long long answer = 0;
	cin >> N;
	vector<long long> roadLength(N-1);
	vector<long long> Price(N);
	for (int i = 0; i < N-1; i++)
	{
		cin >> roadLength[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> Price[i];
	}
	

	for (int i = 0; i < N - 1; i++)
	{
		if (Price[i] < Price[i + 1])
		{
			Price[i + 1] = Price[i];
		}
		answer += Price[i] * roadLength[i];
	}

	cout << answer;
		
	return 0;
}
