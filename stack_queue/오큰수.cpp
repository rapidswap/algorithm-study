#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    stack<int> o;
    stack<int> mn;
    stack<int> nge;
    while (n--)
    {
        int num;
        cin >> num;
        o.push(num);
    }

    bool first = true;
    int Max = 0;
    while (!o.empty())
    {
        int a = o.top();
        o.pop();
        
        if (first)
        {
            nge.push(-1);
            mn.push(a);
            first = false;
            continue;
        }
        while (1)
        {
            if (mn.top() > a)
            {
                nge.push(mn.top());
                mn.push(a);
                break;
            }
            else 
            {
                mn.pop();
            }
            if (mn.empty())
            {
                nge.push(-1);
                mn.push(a);
                break;
            }
        }
    } 
    while (!nge.empty())
    {
        int a = nge.top();
        nge.pop();
        cout << a;
        if(!nge.empty())
        {
            cout << " ";
        }

    }

   
    
    
    return 0;
}
