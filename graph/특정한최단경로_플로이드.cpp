#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9/3; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, E;
    cin >> N >> E;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));


    for (int i = 1; i <= N; ++i)
        dist[i][i] = 0;


    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c); 
    }


    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int u, v;
    cin >> u >> v;
    int path1 = dist[1][u] + dist[u][v] + dist[v][N];
    int path2 = dist[1][v] + dist[v][u] + dist[u][N];

    int answer = min(path1, path2);
    if (answer >= INF)
        cout << -1;
    else
        cout << answer;

    return 0;
}
