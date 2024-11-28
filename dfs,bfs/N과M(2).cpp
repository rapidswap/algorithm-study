#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include <limits.h>
using namespace std;

int n, m;
bool vst[10] = { false };
vector<int> result;

void backtracking(int a, int b) {
    if (b == m) {
        for (int num : result) {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = a; i <= n; i++) {
        if (!vst[i]) {
            vst[i] = true;
            result.push_back(i); 
            backtracking(i + 1, b + 1); 
            result.pop_back(); 
            vst[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    backtracking(1, 0); 
    return 0;
}
