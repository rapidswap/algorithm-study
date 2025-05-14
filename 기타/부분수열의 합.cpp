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

int N,S;
int num[21];
int cnt = 0;

void func(int a,int b) {
    if (a == N) {
        if (b == S) cnt++;
        return;
    }
    func(a + 1, b);
    func(a + 1, b + num[a]);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    func(0, 0);
    if (S == 0) cnt--;
    cout << cnt;
    


    return 0;
}
