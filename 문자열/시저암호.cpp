#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(char ch: s)
    {
        int c;
        if(islower(ch))
        {
            c=ch+n;
            if(c>'z')
            {
                c-=26;
            }
            answer+=(char)c;
        }
        else if(ch==' ')
        {
            answer+=' ';
        }
        else if(isupper(ch))
        {
            c=ch+n;
            if(c>'Z')
            {
               c-=26;
            }

            answer+=(char)c;
        }
    }
    return answer;
}
