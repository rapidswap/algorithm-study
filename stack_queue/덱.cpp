#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    deque<int> dq;

    int n;
    cin >> n;
    
    while (n--)
    {
        string od;
        cin >> od;

        if (od == "push_back")
        {
            int a;
            cin >> a;
            dq.push_back(a);
        }
        if (od == "push_front")
        {
            int a;
            cin >> a;
            dq.push_front(a);
        }
        if (od == "pop_front")
        {
            if (dq.empty()) cout << -1 << '\n';
            else
            {
                cout << dq.front()<<'\n';
                dq.pop_front();
            }
        }
        if (od == "pop_back")
        {
            if (dq.empty()) cout << -1 << '\n';
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        if (od == "size")
        {
            cout << dq.size() << '\n';
        }
        if (od == "empty")
        {
            if (dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        if (od == "front")
        {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front()<<'\n';
        }
        if (od == "back")
        {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }


    return 0;
}
