#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.size();i++)
    {
        stack<char> ch;
        bool isflag=false;
        for(int i=0;i<s.size();i++)
        {
            ;
            if(s[i] == '(' || s[i] == '[' || s[i]== '{')
            {
                isflag=true;
                ch.push(s[i]);
            }
            else
            {
                if(s[i]==')' && ch.top()=='(')
                {
                    ch.pop();
                }
                if(s[i]==']' && ch.top()=='[')
                {
                    ch.pop();
                }
                if(s[i]=='}' && ch.top() =='{')
                {
                    ch.pop();
                }
            }
        }
        if(ch.empty() && isflag) answer++;
        char a= s[0];
        s.erase(s.begin());
        s.push_back(a);
    }
    return answer;
} //https://ansohxxn.github.io/programmers/135/
