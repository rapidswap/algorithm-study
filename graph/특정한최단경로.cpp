#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

void dijkstra(int start, const vector<vector<pair<int, int>>>& nodes, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    dist[start] = 0;
    heap.push({ 0, start });

    while (!heap.empty()) {
        auto node = heap.top();
        heap.pop();

        if (dist[node.second] < node.first) continue;

        for (auto a : nodes[node.second]) {
            if (dist[a.second] > node.first + a.first) {
                dist[a.second] = node.first + a.first;
                heap.push({ dist[a.second], a.second });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<int, int>>> nodes(N + 1);
    for (int i = 1; i <= E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({ c,b });
        nodes[b].push_back({ c,a });
    }

    int u, v;
    cin >> u >> v;
    if (E == 0)
    {
        cout << -1;
        return 0;
    }
    vector<int> distFromStart(N + 1, INT_MAX);
    vector<int> distFromU(N + 1, INT_MAX);
    vector<int> distFromV(N + 1, INT_MAX);

    
    dijkstra(1, nodes, distFromStart);
    
    dijkstra(u, nodes, distFromU);
    
    dijkstra(v, nodes, distFromV);


    int path1 = distFromStart[u] + distFromU[v] + distFromV[N];
    int path2 = distFromStart[v] + distFromV[u] + distFromU[N];

    int result = min(path1,path2);
    if (result >= INT_MAX||result<  0)
        cout << -1;
    else
        cout << result;

  
    return 0;
}
