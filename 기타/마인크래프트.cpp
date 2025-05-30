#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;


int ground[501][501];
int mn = 987654321;
int h;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M,inven;
    cin >> N>>M>>inven;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ground[i][j];
        }
    }

    for (int e = 0; e <= 256; e++) {
        int build = 0;
        int del = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (ground[i][j] > e) {
                    del += ground[i][j] - e;
                }
                else if (ground[i][j] < e) {
                    build += e - ground[i][j];
                }
            }
        }

        if (del + inven >= build) {
            int time = del * 2 + build;
            if (mn >= time) {
                mn = time;
                h = e;
            }
        }
    }
    
    cout << mn << " " << h;

    return 0;
}
