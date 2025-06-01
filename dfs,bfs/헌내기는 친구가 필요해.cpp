#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;


char campus[601][601];
bool vist[601][601];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M;j++) {
            campus[i][j] = str[j];
            if (str[j] == 'I') {
                q.push({ i,j });
            }
        }
    }
    
    int cnt = 0;
    while (!q.empty()) {
        auto a = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = a.first + dy[i];
            int nx = a.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (campus[ny][nx] == 'X' || vist[ny][nx]) continue;
            if (campus[ny][nx] == 'P') cnt++;
            q.push({ ny,nx });
            vist[ny][nx] = true;
        }
    }
    
    if (cnt > 0) {
        cout << cnt;
    }
    else {
        cout << "TT";
    }
    


    return 0;
}
