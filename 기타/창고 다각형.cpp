#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<map>
using namespace std;
typedef long long ll;

int n, m;
int answer = 0;
int arr[1001];
int max_h, max_pos;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

   
    cin >> n;

    int L, H;
    for (int i = 0; i < n; i++) {
        cin >> L >> H;
        arr[L] = H;
        if (max_h < H) {
            max_pos = L;
            max_h = H;
        }
    }
    
    int lH = 0;
    for (int i = 1; i < max_pos; i++) {
        lH = max(lH, arr[i]);
        answer += lH;
    }

    int rH = 0;
    for (int i = 1000; i > max_pos; i--) {
        rH = max(rH, arr[i]);
        answer += rH;
    }

   
    cout << answer+max_h;
    return 0;
}
