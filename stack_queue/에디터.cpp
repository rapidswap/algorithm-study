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
    stack<char> right;
    stack<char> left;

    string edit;
    cin >> edit;

    for (char ch:edit)
    {
        left.push(ch);
    }

    int n;
    cin >> n;


    while (n--)
    {
        char order;
        cin >> order;
        
        if (order == 'P')
        {
            char ch;
            cin >> ch;
            left.push(ch);
        }
        if (order == 'B')
        {
            if(!left.empty())
                left.pop();
        }
        if (order == 'D')
        {
            if (!right.empty())
            {
                char ch = right.top();
                left.push(ch);
                right.pop();
            }
        }
        if (order == 'L')
        {
            if (!left.empty())
            {
                char ch = left.top();
                right.push(ch);
                left.pop();
            }
        }
    }
    while (!left.empty())
    {
        char ch = left.top();
        right.push(ch);
        left.pop();
    }
    while (!right.empty())
    {
        char ch = right.top();
        cout << ch;
        right.pop();
    }

    return 0;
}
