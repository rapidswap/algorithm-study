#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int y, x, d;
    cin >> y >> x >> d;

    int map[50][50];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int dy[4] = { -1, 0, 1, 0 };  
    int dx[4] = { 0, 1, 0, -1 };  
    int cnt = 0;

    while (true) {
        bool sw = false;

        if (map[y][x] == 0) {
            map[y][x] = 2;
            cnt++;
        }

        for (int i = 1; i < 5; i++) {
            int ny = y + dy[(d - i + 4) % 4];
            int nx = x + dx[(d - i + 4) % 4];

            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (map[ny][nx] == 0) {
                    d = (d - i + 4) % 4;
                    y = ny;
                    x = nx;
                    sw = true;
                    break;
                }
            }
        }

        if (!sw) {
            int ny = y - dy[d];
            int nx = x - dx[d];
            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (map[ny][nx] == 1) {
                    break; 
                }
                else {
                    y = ny;
                    x = nx;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}//https://www.youtube.com/watch?v=ql82YcFisUI
