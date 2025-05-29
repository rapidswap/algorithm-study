#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int dz[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dx[] = { 0, 0, 0, 0, 1, -1 };

int tomato[101][101][101];
int dist[101][101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, N, Z;
    cin >> M >> N >> Z;

    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < Z; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) {
                    q.push({ i, j, k });
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        int z = get<0>(pos);
        int y = get<1>(pos);
        int x = get<2>(pos);

        for (int dir = 0; dir < 6; dir++) {
            int nz = z + dz[dir];
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (nz < 0 || nz >= Z || ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (tomato[nz][ny][nx] != 0 || dist[nz][ny][nx] != -1) continue;

            dist[nz][ny][nx] = dist[z][y][x] + 1;
            q.push({ nz, ny, nx });
        }
    }

    int maxDist = 0;
    for (int i = 0; i < Z; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[i][j][k] == 0 && dist[i][j][k] == -1) {
                    cout << -1 << '\n';
                    return 0;
                }
                maxDist = max(maxDist, dist[i][j][k]);
            }
        }
    }

    cout << maxDist << '\n';
    return 0;
}
