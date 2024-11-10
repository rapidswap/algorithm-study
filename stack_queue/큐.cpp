#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    queue<int> q;
    while (n--)
    {
        string order;
        cin >> order;

        if (order == "push")
        {
            int a;
            cin >> a;
            q.push(a);
        }
        if (order == "pop")
        {
            if (q.empty()) cout << -1 << '\n';
            else {
                int a = q.front();
                q.pop();
                cout << a << '\n';
            }
        }
        if (order == "size")
        {
            cout << q.size() << '\n';
        }
        if (order == "empty")
        {
            if (q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        if (order == "front")
        {
            if (q.empty()) cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
            }
        }
        if (order == "back")
        {
            if (q.empty()) cout << -1 << '\n';
            else
            {
                cout << q.back() << '\n';
            }
        }
    }
    

    

    return 0;
}
