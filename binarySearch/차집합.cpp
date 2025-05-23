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

    vector<int> answer;

    cin >> n>>m;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    
    sort(x, x + n);
    sort(y, y + m);

    for (int i = 0; i < n; i++) {
        if (binary_search(y, y + m, x[i])) continue;
        else {
            answer.push_back(x[i]);
        }
    }

    if (answer.size() == 0) cout << 0;
    else {
        cout << answer.size() << '\n';
        for (int nn : answer) {
            cout << nn << " ";
        }
    }
    

    return 0;
}
