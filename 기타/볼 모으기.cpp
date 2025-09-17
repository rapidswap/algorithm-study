#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int N;
    int answer = INT_MAX;
    int cnt = 0;
    cin >> N;
    cin >> str;

    bool sw = false;
    
    for (int i = 0; i < N; i++) {
        if (str[i] == 'B') sw = true;
        if (sw && str[i] == 'R') cnt++;
    }
    answer = min(answer, cnt);
    cnt = 0;
    sw = false;

    for (int i = 0; i < N; i++) {
        if (str[i] == 'R') sw = true;
        if (sw && str[i] == 'B') cnt++;
    }
    answer = min(answer, cnt);
    cnt = 0;
    sw = false;

    for (int i = N-1; i >= 0; i--) {
        if (str[i] == 'B') sw = true;
        if (sw && str[i] == 'R') cnt++;
    }
    answer = min(answer, cnt);
    cnt = 0;
    sw = false;

    for (int i = N-1; i >= 0; i--) {
        if (str[i] == 'R') sw = true;
        if (sw && str[i] == 'B') cnt++;
    }
    answer = min(answer, cnt);
    cnt = 0;
    sw = false;

    cout << answer;
    return 0;
}
