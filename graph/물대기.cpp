#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

int N;
bool vist[302];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int cost;
    vector<vector<pair<int, int>>> nodes(N+2);
    for (int i = 1; i <= N; i++) {
        cin >> cost;
        nodes[i].push_back({ cost,N + 1 });
        nodes[N + 1].push_back({cost, i});
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> cost;
            if (i == j) continue;
            nodes[i].push_back({ cost,j });
            nodes[j].push_back({ cost,i });
        }
        
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({ 0,1 });

    int answer = 0;
    while (!heap.empty()) {
        auto node = heap.top(); heap.pop();

        if (!vist[node.second]) {
            answer += node.first;
            vist[node.second] = true;
            for (auto a : nodes[node.second]) {
                heap.push({ a.first,a.second });
            }
        }
        
    }
   
    cout << answer;

    return 0;
}
