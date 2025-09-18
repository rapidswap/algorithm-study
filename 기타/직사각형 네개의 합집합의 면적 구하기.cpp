#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    int board[100][100] = { 0 };
    int x1, x2, y1, y2;
    for (int i = 0; i < 4; i++) {   
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) {
                if (board[j][k] == 0) {
                    board[j][k] = 1;
                    answer++;
                }
            }
        }
    }
    cout << answer<<'\n';

    return 0;
}
