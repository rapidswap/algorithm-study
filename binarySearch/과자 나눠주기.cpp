#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int n,m;
int x[500001];
int y[500001];
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n>>m;

    vector<int> snack(m);
    for (int i = 0; i < m; i++) {
        cin >> snack[i];
    }

    sort(snack.begin(), snack.end());
    
    int st = 1;
    int ed = *max_element(snack.begin(), snack.end());
    int answer = 0;
    while (st <= ed) {
        int mid = (st + ed) / 2;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += snack[i] / mid;
        }

        if (cnt < n) {
            ed = mid - 1;
        }
        else if (cnt >= n) {
            st = mid + 1;
            answer = mid;
        }
    }

    cout << answer;

    return 0;
}
