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

    int N;
    cin >> N;
    
    vector<pair<int, int>> works(N);

    for (int i = 0; i < N; i++) {
        cin >> works[i].first >> works[i].second;
    }

    sort(works.begin(), works.end(),cmp);

    int cnt = 1;
    int workEnd = works[0].second;

    for (int i = 1; i < N;i++) {
        if (workEnd > works[i].first) continue;
        else if(workEnd <= works[i].first) {
            workEnd = works[i].second;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
