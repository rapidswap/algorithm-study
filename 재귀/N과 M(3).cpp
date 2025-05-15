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

int N,M;
int cnt = 1;
bool vist[8];
int nums[8];
void func(int a) {
    if (a == M) {
        for (int j = 0; j < M; j++) {
            cout << nums[j] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!vist[a]) {
            vist[a] = true;
            nums[a] = i;
            func(a + 1);
            vist[a] = false;
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    func(0);


    return 0;
}
