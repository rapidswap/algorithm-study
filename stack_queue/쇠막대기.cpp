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
    int sum = 0;
    int flag = 0;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        
        if(str[i] == '(')
            stk.push(str[i]);
        else
        { 
            stk.pop();
            if (str[i - 1] == '(')
            {
                sum += stk.size();
            }
            else sum++;
            
        }
    }
    cout << sum;
    
    
    return 0;
}
