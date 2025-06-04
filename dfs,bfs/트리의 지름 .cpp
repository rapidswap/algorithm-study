#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<pair<int, int>>> adj(N + 1);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        int b;
        while (cin >> b && b != -1) {
            int c;
            cin >> c;
            adj[a].push_back({ b, c });
        }
    }


    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q;

    int maxCost = 0;
    int longNode = 1;

    q.push({ 1, 0 });
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (cost > maxCost) {
            maxCost = cost;
            longNode = node;
        }

        for (auto a : adj[node]) {
            if (!visited[a.first]) {
                visited[a.first] = true;
                q.push({ a.first, cost + a.second });
            }
        }
    }


    fill(visited.begin(), visited.end(), false);
    while (!q.empty()) q.pop();  

    maxCost = 0;  
    q.push({ longNode, 0 });
    visited[longNode] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int cost = q.front().second;
        q.pop();

        maxCost = max(maxCost, cost); 

        for (auto a : adj[node]) {
            if (!visited[a.first]) {
                visited[a.first] = true;
                q.push({ a.first, cost + a.second });
            }
        }
    }

    cout << maxCost << '\n';

    return 0;
}
