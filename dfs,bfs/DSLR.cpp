#include <iostream>
#include <queue>
#include <vector>  // 추가 필요
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        vector<bool> vist(10000, false);
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << "\n";
            continue; 
        }

        queue<pair<int, string>> q;
        q.push({ a, "" });
        vist[a] = true;

        bool found = false;  

        while (!q.empty() && !found) {
            auto cur = q.front();
            q.pop();


            int d_result = cur.first * 2 % 10000;
            if (d_result == b) {
                cout << cur.second + "D\n";
                found = true;
                break;
            }
            if (!vist[d_result]) {
                vist[d_result] = true;
                q.push({ d_result, cur.second + "D" });
            }


            int s_result = (cur.first == 0) ? 9999 : cur.first - 1;
            if (s_result == b) {
                cout << cur.second + "S\n";
                found = true;
                break;
            }
            if (!vist[s_result]) {
                vist[s_result] = true;
                q.push({ s_result, cur.second + "S" });
            }

            int l_result = (cur.first % 1000) * 10 + cur.first / 1000;
            if (l_result == b) {
                cout << cur.second + "L\n";
                found = true;
                break;
            }
            if (!vist[l_result]) {
                vist[l_result] = true;
                q.push({ l_result, cur.second + "L" });
            }


            int r_result = (cur.first % 10) * 1000 + cur.first / 10;
            if (r_result == b) {
                cout << cur.second + "R\n";
                found = true;
                break;
            }
            if (!vist[r_result]) {
                vist[r_result] = true;
                q.push({ r_result, cur.second + "R" });
            }
        }
    }

    return 0;
}
