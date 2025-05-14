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


int Z(int n, int r, int c) {
    if (n == 0) return 0;
    int half = pow(2,n)/2;
    if (r < half && c < half) return Z(n - 1, r, c);
    if (r < half && c >= half) return half * half + Z(n - 1, r, c - half);
    if (r >= half && c < half) return 2 * half * half + Z(n - 1, r - half, c);
    return 3 * half * half + Z(n - 1, r - half, c - half);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, r, c;
    cin >> n >> r >> c;
    cout << Z(n, r, c);


    return 0;
}
