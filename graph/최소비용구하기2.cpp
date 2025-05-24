#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

int N,M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    vector<vector<pair<int, int>>> nodes(N + 1);
    vector<int> route(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({ c,b });
    }
    
    int start, end;
    cin >> start >> end;

    heap.push({ 0,start });
    dist[start] = 0;

    while (!heap.empty()) {
        auto node = heap.top(); heap.pop();

        if (dist[node.second] < node.first) continue;

        for (auto a : nodes[node.second]) {
            if (dist[a.second] > node.first + a.first) {
                dist[a.second] = node.first + a.first;
                heap.push({ dist[a.second],a.second });
                route[a.second] = node.second;
            }
        }
        
    }

    cout << dist[end] << '\n';

    int temp = end;
    vector<int> routeV;
    while (temp) {
        routeV.push_back(temp);
        temp = route[temp];
    }

    cout << routeV.size() << '\n';
    
    for (int i = routeV.size() - 1; i >= 0; i--) {
        cout << routeV[i] << ' ';
    }

    return 0;
}
