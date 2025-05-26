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

int testcase;
int dy[] = { 1,1,2,2,-1,-1,-2,-2};
int dx[] = { -2,2,-1,1,-2,2,-1,1 };
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        int line;
        cin >> line;

        int stX, stY, edX, edY;
        cin >> stX >> stY >> edX >> edY;

        queue<pair<int, int>> q;
        int dist[301][301];
        bool vist[301][301];
        memset(dist, -1, sizeof(dist));
        memset(vist, false, sizeof(vist));
        q.push({ stY,stX });
        dist[stY][stX] = 0;
        vist[stY][stX] = true;

        while (!q.empty()) {
            auto a = q.front(); q.pop();

            for (int j = 0; j < 8; j++) {
                int ny = a.first + dy[j];
                int nx = a.second + dx[j];

                if (nx < 0 || ny < 0 || nx >= line || ny >= line)continue;
                if (vist[ny][nx] || dist[ny][nx]>0)continue;

                vist[ny][nx] = true;
                dist[ny][nx] = dist[a.first][a.second] + 1;
                q.push({ ny,nx });
            }
        }

        cout << dist[edY][edX]<<'\n';


    }
    
   


    return 0;
}
