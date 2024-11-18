#include<iostream>
#include<vector>
#include<string>

#include<algorithm>
#include<queue>
#include<unordered_map>
#include<cmath>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n,m;
    cin >> n>>m;

    vector<long long> line;
    while (n--)
    {
        int a;
        cin >> a;
        line.push_back(a);
    }
    long long M = *max_element(line.begin(), line.end());
    long long start = 1;
    long long end = M;
    long long result = 0;
    while (start <= end)
    {
        long long total = 0;
        long long mid = (start + end) / 2;
        for (int i = 0; i < line.size(); i++)
        {
            total += line[i] / mid;
        }
        if (total >= m)
        {
            start = mid + 1;
            result = mid;
        }
        if (total < m)
        {
            end = mid - 1;
        }
    }
    cout << result;
    
    


    return 0;
}
