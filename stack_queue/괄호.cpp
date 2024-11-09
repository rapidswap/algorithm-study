#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    
    cin >> n;
    while (n--)
    {
        string test;
        cin >> test;
        stack<char> stk;
        bool flag = true;
        for (char c : test) {
            if (c == '(') {
                stk.push(c);
            }
            else if (c == ')') {
                if (stk.empty()) {
                    flag = false;
                    break;
                }
                stk.pop();
            }
        }
        if (stk.empty()&& flag) cout << "YES\n";
        else cout << "NO\n";
    }
    

    

    return 0;
}
