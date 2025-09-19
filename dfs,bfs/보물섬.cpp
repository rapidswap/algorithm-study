#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;
typedef long long ll;

int N, M;
char board[51][51];


int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    int dist[51][51];
    memset(dist, -1, sizeof(dist));
    int current_max_dist = 0;
    q.push({ y,x });
    dist[y][x] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (dist[ny][nx] != -1 || board[ny][nx] == 'W') continue;
            q.push({ ny,nx });
            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            current_max_dist = max(current_max_dist, dist[ny][nx]);
        }
    }
    return current_max_dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            board[i][j] = str[j];
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'L') {
                answer = max(answer, bfs(i, j));
            }
        }
    }

    cout << answer;

    return 0;
}
