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
    bool isflag = false;
    vector<char> answer;
    stack<char> stk;
    string str;
    cin.ignore(0);
    getline(cin, str);
    str += " ";
    for (int i = 0; i < str.size(); i++)
    {
        if (!isflag&&str[i] == ' ')
        {
            while (!stk.empty())
            {
                answer.push_back(stk.top());
                stk.pop();
            }
            answer.push_back(' ');
        }
        if (str[i] == '<')
        {
            isflag = true;
            while (!stk.empty())
            {
                answer.push_back(stk.top());
                stk.pop();
            }
        }

        if (isflag)
            answer.push_back(str[i]);
        else
            if(str[i]!=' ')
                stk.push(str[i]);

        if (str[i] == '>')
            isflag = false;
        
    }

    for (char ch : answer)
    {
        cout << ch;
    }
    return 0;
}
