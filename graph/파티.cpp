#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

int N,M,X;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> M >> X;

    vector<vector<int>> dist(N+1,vector<int>(N + 1,INT_MAX));
    vector<vector<pair<int, int>>> nodes(N+1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({ c,b });
    }
    

    for (int i = 1; i <= N; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        dist[i][i] = 0;
        heap.push({ 0,i });
        while (!heap.empty()) {
            auto node = heap.top(); heap.pop();
            if (dist[i][node.second] < node.first) continue;

            for (auto a : nodes[node.second]) {
                if (dist[i][a.second] > node.first + a.first) {
                    dist[i][a.second] = node.first + a.first;
                    heap.push({ dist[i][a.second],a.second });
                }
            }
        }
    }

    int answer = INT_MIN;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, dist[i][X]+dist[X][i]);
    }
    cout << answer;
    return 0;
}
