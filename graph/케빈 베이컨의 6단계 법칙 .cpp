#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin >> N>>M;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, 999999999));
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
        
    }

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            for (int k = 1; k <= N; k++) {
                dist[i][k] = min(dist[i][k], dist[i][j] + dist[j][k]);
            }
        }
    }

    int minDist = INT_MAX;
    int minNode = -1;
    vector<int> ranges;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += dist[i][j];
        }
        if (minDist > sum) {
            minDist = sum;
            minNode = i;
        }
    }
    cout << minNode;
    
    return 0;
}
