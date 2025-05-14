#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <stack>
#include <cmath>
#include <unordered_set>
using namespace std;

int n;
bool vist1[40]; // 열
bool vist2[40]; // 왼오대각 x+y
bool vist3[40]; // 오왼대각 x-y+n-1

int cnt = 0;

void func(int a) {
    if (a == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (vist1[i] || vist2[i+a] || vist3[a-i+n-1]) continue;

        vist1[i] = true;
        vist2[i + a] = true;
        vist3[a-i + n - 1] = true;
        func(a + 1);
        vist1[i] = false;
        vist2[i + a] = false;
        vist3[a - i + n - 1] = false;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    func(0);
    cout << cnt;
    


    return 0;
}
