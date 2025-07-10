#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int n;
int Ti[16] = { 0, };
int Pi[16] = { 0, };
int res[16] = { 0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Ti[i] >> Pi[i];
    }

    int deadline;
    for (int i = n; i > 0; i--) {
        deadline = i + Ti[i];
        if (deadline > n + 1) {
            res[i] = res[i + 1];
        }
        else {
            res[i] = max(res[i+1], res[deadline]+Pi[i]);
        }
    }

    cout << res[1];
    
    

    return 0;
}
