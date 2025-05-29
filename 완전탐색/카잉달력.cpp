#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        bool found = false;

        for (int k = x; k <= M * N; k += M) {
            if ((k - 1) % N + 1 == y) {
                cout << k << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << '\n';
        }
    }

    return 0;
}
