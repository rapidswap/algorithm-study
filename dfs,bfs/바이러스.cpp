#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
bool visited[101];
int cnt = 0;
vector<int> computers[101];

void dfs(int start) { 
    for (int i = 0; i < computers[start].size(); i++)
    {
        if (!visited[computers[start][i]])
        {
            cnt++;
            visited[computers[start][i]] = true;
            dfs(computers[start][i]);
            
        }
    }
}

int main() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int st, ed;
        cin >> st >> ed;
        computers[st].push_back(ed);
        computers[ed].push_back(st);
    }

    for (int i = 0; i < N; i++)
    {
        sort(computers[i].begin(), computers[i].end());
    }

    visited[1] = true;
    dfs(1);
    cnt = cnt;
    if (cnt == -1) cout << 0;
    cout << cnt;
              
}
