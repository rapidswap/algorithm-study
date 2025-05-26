#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cstring>
using namespace std;

int L, C;
vector<char> answer;
vector<char> c(16);

void func(int idx, int cnt, int aeiou) {
    if (cnt == L) {
        if (L-aeiou >= 2 && aeiou>=1) {
            for (int i = 0; i < L; i++) {
                cout << answer[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int i = idx; i < C; i++) {  
        answer.push_back(c[i]);
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u') {
            func(i + 1, cnt + 1, aeiou+1);
        }
        else {
            func(i + 1, cnt + 1, aeiou);
        }
        answer.pop_back();           
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.begin() + C);

    func(0, 0, 0);
    return 0;
}
