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
    cin >> str;

    int cnt = 0;
    int answer = str.size();
    for (auto c : str) {
        if (c == 'a') cnt++;
    }

    for (int i = 0; i < str.size(); i++) {
        int a = cnt, b = 0;
        for (int j = i; j < i + str.size(); j++) {
            if (a == 0) break;
            if (str[j % str.size()] == 'b') {
                b++;
                a--;
            }
            else a--;
        }
        answer = min(answer, b);
    }
    cout << answer;
    return 0;
}
