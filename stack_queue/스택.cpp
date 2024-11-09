#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack<int> stk;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string order;
        int num;
        cin >> order;
        if (order == "push")
        {
            cin >> num;
            stk.push(num);
        }
        if (order == "top")
        {
            if (stk.empty()) cout << "-1"<<'\n';
            else cout << stk.top()<<'\n';
        }
        if (order == "size")
            cout << stk.size() << '\n';
        if (order == "pop")
        {
            if (stk.empty()) cout << "-1" << '\n';
            else
            {
                cout << stk.top()<<'\n';
                stk.pop();
            }
        }
        if (order == "empty")
        {
            if (stk.empty()) cout << "1" << '\n';
            else cout << "0" << '\n';
        }
    }
    

    return 0;
}
