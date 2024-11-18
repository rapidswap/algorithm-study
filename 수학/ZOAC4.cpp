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


    float h,w,n,m;
    cin >> h >> w >> n >> m;
    int answer=int(ceil(h / (n+1))) * int(ceil(w / (m+1)));
    cout << answer;
    
    
    


    return 0;
}
