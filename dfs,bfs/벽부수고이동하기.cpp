#include <iostream>
#include <queue>
#include <tuple>    // 큐에 세 가지 정보를 담기 위해 tuple을 사용
#include <string>   // 공백 없는 입력을 받기 위해 string을 사용
#include <algorithm>// min 함수를 사용
#include <cstring>  // memset 함수를 사용

using namespace std;


int board[1001][1001];

int dist[1001][1001][2];
int N, M;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void bfs() {
    queue<tuple<int, int, int>> q;

    q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;

    while (!q.empty()) {
        tuple<int, int, int> cur = q.front();
        int y = get<0>(cur);
        int x = get<1>(cur);
        int broken = get<2>(cur);
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            if (board[ny][nx] == 0 && dist[ny][nx][broken] == -1) {
                dist[ny][nx][broken] = dist[y][x][broken] + 1;
                q.push({ ny, nx, broken });
            }

            if (board[ny][nx] == 1 && broken == 0 && dist[ny][nx][1] == -1) {
                dist[ny][nx][1] = dist[y][x][0] + 1;
                q.push({ ny, nx, 1 });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            board[i][j] = row[j] - '0';
        }
    }

    memset(dist, -1, sizeof(dist));

    bfs();

    int result_not_broken = dist[N - 1][M - 1][0];
    int result_broken = dist[N - 1][M - 1][1];

    if (result_not_broken == -1 && result_broken == -1) {
        cout << -1 << "\n";
    }
    else if (result_not_broken == -1) {
        cout << result_broken << "\n";
    }
    else if (result_broken == -1) {
        cout << result_not_broken << "\n";
    }
    else {
        cout << min(result_not_broken, result_broken) << "\n";
    }

    return 0;
}
