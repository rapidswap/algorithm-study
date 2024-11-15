#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> v;
bool visited[2000] = { false };
bool found = false;

void dfs(int from,int cnt)
{
    if (cnt >= 4)
    {
        found = true;
        return;
    }
    visited[from] = true;
    for (int i = 0; i < v[from].size(); i++)
    {
        int next = v[from][i];
        if (!visited[next])
        {
            //visited[i] = true;
            dfs(next, cnt + 1);
           // visited[i] = false;
        }
    }
    visited[from] = false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    v.assign(n, vector<int>(0, 0));
    
    for (int i = 0; i < m; i++)
    {
        int from;
        int to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i, 0);
        if(found)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
