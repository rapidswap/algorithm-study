#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> dist(N, vector<int>(N, 999999999));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (a == 1) dist[i][j] = 1;
        }
    }


    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (dist[i][j] != 999999999 && dist[j][k] != 999999999)
                    dist[i][k] = min(dist[i][j] + dist[j][k], dist[i][k]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == 999999999) {
                cout << 0 << ' ';
            }
            else
                cout << 1 << ' ';
        }
        cout << '\n';
    }
    

    return 0;
}
