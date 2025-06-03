#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int board[501][501];
int maxSum = 0;


vector<vector<pair<int, int>>> tetrominos = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},  
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},  

    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},

    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},  
    {{0, 1}, {1, 0}, {1, 1}, {2, 1}},  
    {{1, 0}, {1, 1}, {1, 2}, {0, 1}},  
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},  

    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},  
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},  


    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},  
    {{0, 1}, {1, 0}, {1, 1}, {2, 0}},  

    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},  
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},  
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},  
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},  

    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},  
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},  
    {{0, 1}, {1, 1}, {2, 0}, {2, 1}}, 
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}}   
};

bool isValid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (auto shape : tetrominos) {
                int sum = 0;
                bool canPlace = true;

                for (auto pos : shape) {
                    int newR = i + pos.first;
                    int newC = j + pos.second;

                    if (!isValid(newR, newC)) {
                        canPlace = false;
                        break;
                    }
                    sum += board[newR][newC];
                }

                if (canPlace) {
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    solve();

    cout << maxSum << '\n';

    return 0;
}
