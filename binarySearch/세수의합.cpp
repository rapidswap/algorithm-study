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

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a[1001];
    vector<int> two;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            two.push_back(a[i] + a[j]);
        }
    }

    sort(two.begin(), two.end());
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (binary_search(two.begin(), two.end(), a[i] - a[j])) {
                cout << a[i];
                return 0;
            }
        }
    }


    

    return 0;
}
