#include <iostream>
#include <queue>
#include <tuple>   
#include <string>   
#include <algorithm>
#include <cstring>  

using namespace std;

int N;
vector<vector<pair<int, int>>> adj(10001);
bool vist[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }

    queue<pair<int, int>> q;
    q.push({ 1,0 });
    vist[1] = true;

    int maxCost=-1;
    int longNode = -1;
    while (!q.empty()) {
        auto node = q.front(); q.pop();

        if (maxCost < node.second) {
            maxCost = node.second;
            longNode = node.first;
        }

        for (auto a : adj[node.first]) {
            if (!vist[a.first]) {
                vist[a.first] = true;
                q.push({ a.first,node.second + a.second });
            }
        }
    }

    memset(vist, false, sizeof(vist));
    while (!q.empty()) q.pop();

    maxCost = 0;
    q.push({ longNode,0 });
    vist[longNode] = true;

    while (!q.empty()) {
        auto node = q.front(); q.pop();
        
        maxCost = max(maxCost, node.second);

        for (auto a : adj[node.first]) {
            if (!vist[a.first]) {
                vist[a.first] = true;
                q.push({ a.first,a.second + node.second });
            }
        }
    }

    cout << maxCost;

   
    return 0;
}
