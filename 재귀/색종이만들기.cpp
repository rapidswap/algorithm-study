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

int white = 0;
int blue = 0;
vector<vector<int>> board(129, vector<int>(129));


void func(int x, int y, int k) {
    bool cut = false;
    int fc = board[y][x];
    for (int i = y; i < y+k; i++) {
        for (int j = x; j < x+k; j++) {
            if (board[i][j] != fc) {
                cut = true;
                break;
            }
        }
    }

    if (cut) {
        func(x, y, k / 2);
        func(x + k / 2, y, k / 2);
        func(x, y + k / 2, k / 2);
        func(x + k / 2, y + k / 2, k / 2);
    }
    else {
        if (fc == 1) {
            blue++;
        }
        else {
            white++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    func(0, 0, N);
    cout << white << '\n';
    cout << blue << '\n';


    


    return 0;
}
