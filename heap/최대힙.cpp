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

    priority_queue<int, vector<int>> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            if (pq.empty()) {
                cout << 0<<'\n';
            }
            else {
                cout << pq.top()<<'\n';
                pq.pop();
            }
        }
        else {
            pq.push(a);
        }
    }

    return 0;
}
