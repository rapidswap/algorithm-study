#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstring>  
using namespace std;


char board[21][21];
bool alphaVisited[26]; 
int R_global, C_global; 
int maxPathLength = 0; 

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void dfs(int y, int x, int currentPathLength) {
    maxPathLength = max(maxPathLength, currentPathLength);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && nx >= 0 && ny < R_global && nx < C_global) {
            int charIndex = board[ny][nx] - 'A';

            if (!alphaVisited[charIndex]) {
                alphaVisited[charIndex] = true;

                dfs(ny, nx, currentPathLength + 1);

                alphaVisited[charIndex] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R_global >> C_global;


    for (int i = 0; i < R_global; i++) {
        for (int j = 0; j < C_global; j++) {
            cin >> board[i][j];
        }
    }


    alphaVisited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1); 


    cout << maxPathLength << '\n';

    return 0;
}
