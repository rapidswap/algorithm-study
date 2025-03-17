#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++)
	{
		unordered_map<int, int> team;
		unordered_map<int, int> rank;
		unordered_map<int, int> teamcnt;
		unordered_map<int, int> five;
		vector<int> point;
		int N;
		cin >> N;

		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			team[a]++;
			point.push_back(a);
		}

		for (auto it = team.begin(); it != team.end();)
		{
			if (it->second < 6)
			{
				it = team.erase(it);
			}
			else
				++it;
		}

		int points = 1;
		for (int j = 0; j < point.size(); j++)
		{
			if (team.find(point[j]) != team.end())
			{
				points++;
				teamcnt[point[j]]++;
				if (teamcnt[point[j]] == 6)
				{
					continue;
				}
				else if (teamcnt[point[j]] == 5)
				{
					five[point[j]] = points;
				}
				else 
					rank[point[j]] += points;
				
			}
		}


		int top = -1;
		int topPoint = INT_MAX;
		for(auto a: rank)
		{ 
			if (a.second == topPoint)
			{
				if (five[top] < five[a.first])
				{
					continue;
				}
				else
				{
					top = a.first;
					continue;
				}
			}
			if (a.second < topPoint)
			{
				topPoint = a.second;
				top = a.first;
			}
		}
		cout << top << '\n';
	}
	return 0;
}
