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

    int deg[32001] = { 0 };
    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) q.push(i);
    }

    vector<int> answer;
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        answer.push_back(cur);
        for (int a : adj[cur]) {
            deg[a]--;
            if (deg[a] == 0) q.push(a);
        }
    }

    for (int a : answer) {
        cout << a << ' ';
    }


   

    return 0;
}
