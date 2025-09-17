#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

const int INF = 1e9; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, D;
    cin >> N >> D;


    vector<vector<pair<int, int>>> graph(D + 1);


    for (int i = 0; i < D; i++) {
        graph[i].push_back({ i + 1, 1 });
    }


    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > D || b > D) continue;
        graph[a].push_back({ b, c });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(D + 1, INF);


    dist[0] = 0;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int current_dist = cur.first;
        int current_node = cur.second;


        if (dist[current_node] < current_dist) continue;


        for (auto edge : graph[current_node]) {
            int neighbor_node = edge.first;
            int edge_weight = edge.second;

            int new_dist = current_dist + edge_weight;

            if (new_dist < dist[neighbor_node]) {
                dist[neighbor_node] = new_dist;
                pq.push({ new_dist, neighbor_node });
            }
        }
    }

    cout << dist[D];
    return 0;
}
