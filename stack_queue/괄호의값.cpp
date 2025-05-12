#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>
using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.second < b.second;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    char pre = ' ';
    int answer = 0;
    int tmp = 1;
    stack<char> stk;

    for (auto c : str) {
        int a;
        if (c == '(' || c == '[') {
            stk.push(c);
            if (c == '(') {
                tmp *= 2;
            }
            else if (c == '[') {
                tmp *= 3;
            }
        }
        else {
            if (c == ')') {
                if (stk.empty()) {
                    answer = 0;
                    break;
                }
                if (stk.top() == '[') {
                    answer = 0;
                    break;
                }
                stk.pop();

                if (pre == '(') {
                    answer += tmp;
                    tmp /=2;
                }
                else {
                    tmp /= 2;
                }
            }
            else {
                if (stk.empty()) {
                    answer = 0;
                    break;
                }
                if (stk.top() == '(') {
                    answer = 0;
                    break;
                }
                stk.pop();
                if (pre == '[') {
                    answer += tmp;
                    tmp /= 3;
                }
                else
                    tmp /= 3;
            }
        }
        pre = c;
    }
    if (!stk.empty())
        answer = 0;
    cout << answer;
    return 0;
}
