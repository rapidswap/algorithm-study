#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int M, N, K;
int board[101][101] = { 0 };

int dy[] = {0,1,0,-1};
int dx[] = { 1,0,-1,0 };

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    int cnt = 0;
    q.push({ y,x });

    board[y][x] = 1;
    cnt++;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
            if (board[ny][nx] == 1)continue;
            q.push({ ny,nx });
            board[ny][nx] = 1;
            cnt++;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N >> K;
    vector<int> answer;

    int x1, x2, y1, y2;
    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) {
                board[k][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                answer.push_back(bfs(i, j));
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i]<<' ';
    }
    
    return 0;
}
