#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int n, m;
int board[100][100];
bool chk[100][100];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    

    int clearTime=0;
    vector<int> cheese;


    while (1) {
        int cheeseCnt = 0;
        queue<pair<int, int>> q;
        q.push({ 0,0 });
        chk[0][0] = true;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if (ny<0 || ny>n || nx<0 || nx>m) continue;
                if (chk[ny][nx]) continue;

                if (board[ny][nx] == 1) {
                    cheeseCnt++;
                    chk[ny][nx] = true;
                    board[ny][nx] = 0;
                }
                else {
                    chk[ny][nx] = true;
                    q.push({ ny,nx });
                }
            }
        }

        cheese.push_back(cheeseCnt);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                chk[i][j] = false;
            }
        }

        if (cheeseCnt == 0) break;

        clearTime++;
    }
    

    cout << clearTime << '\n';
    cout << cheese[cheese.size() - 2];
    return 0;
}
