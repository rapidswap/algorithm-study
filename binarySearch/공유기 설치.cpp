#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,c;
int pos[200001];
int answer = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos, pos + n);

    int start = 1;
    int end = pos[n - 1]-pos[0];

    while (start <= end) {
        int mid = (start + end) / 2;
        int st = pos[0];
        int router = 1;

        for (int i = 1; i < n; i++) {
            if (pos[i] - st >= mid) {
                router++;
                st = pos[i];
            }
        }

        if (router >= c) {
            answer = max(mid, answer);
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << answer;
    return 0;
}
