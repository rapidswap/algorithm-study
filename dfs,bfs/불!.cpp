#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>
using namespace std;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int fireDist[1001][1001];
int jDist[1001][1001];
string board[1001];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    queue<pair<int, int>> fq;
    queue<pair<int, int>> jq;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++) {
        fill(fireDist[i], fireDist[i] + M, -1);
        fill(jDist[i], jDist[i] + M, -1);
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'F') {
                fq.push({ i,j });
                fireDist[i][j] = 0;
            }
            else if (board[i][j] == 'J') {
                jq.push({ i,j });
                jDist[i][j] = 0;
            }
            
        }
    }


    while (!fq.empty()) {
        auto mv = fq.front();
        fq.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = mv.first + dy[i];
            int nx = mv.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (board[ny][nx] == '#' || fireDist[ny][nx]>=0) continue;

            fireDist[ny][nx] = fireDist[mv.first][mv.second] + 1;
            fq.push({ ny,nx });
        }
    }

    while (!jq.empty()) {
        auto mv = jq.front();
        jq.pop();

        for (int i = 0; i < 4; i++) {
            int ny = mv.first + dy[i];
            int nx = mv.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                cout << jDist[mv.first][mv.second]+1;
                return 0;
            }
            if (board[ny][nx] == '#' || jDist[ny][nx] >= 0) continue;
            if (fireDist[ny][nx]!=-1 && fireDist[ny][nx] <= jDist[mv.first][mv.second]+1)continue;
            jDist[ny][nx] = jDist[mv.first][mv.second] + 1;
            jq.push({ ny,nx });
        }
    }

    cout << "IMPOSSIBLE";


    return 0;
}
