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

int dy[] = { 0,1,0,-1 };
int dx[] = { -1,0,1,0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));
    vector<vector<bool>> vist(N, vector<bool>(M, false));
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int,int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                q.push({ i,j });
                vist[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto a = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = a.first + dy[i];
            int nx = a.second + dx[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (vist[ny][nx] || board[ny][nx] == 0 || dist[ny][nx]>0) continue;

            vist[ny][nx] = true;
            dist[ny][nx] = dist[a.first][a.second] + 1;
            q.push({ ny,nx });
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == -1) {
                if (board[i][j] == 0)
                    cout << 0 << ' ';
                else
                    cout << dist[i][j] << ' ';
            }
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
