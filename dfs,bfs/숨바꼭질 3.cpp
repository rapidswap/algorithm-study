#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int dist[100001];
int vist[100001];
int mv[] = { -1,1 };
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int a = q.front();
        vist[a]; q.pop();
        if (a == m) break;
        
        if (!vist[a * 2] && a*2<100001) {
            vist[a * 2] = true;
            q.push(a * 2);
            dist[a * 2] = dist[a];
        }
        for (int i = 0; i < 2; i++) {
            int nx = a + mv[i];
            if (nx < 0 || nx >= 100001) continue;
            if (vist[nx]) continue;
            q.push(nx);
            vist[nx] = true;
            dist[nx] = dist[a] + 1;
        }
    }
    cout << dist[m];
    return 0;
}
