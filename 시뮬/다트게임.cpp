#include <string>
#include <queue>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    queue<char> q;
    string num;
    bool first=true;
    bool second=false;
    int tmp;
    for(char c: dartResult)
    {
        q.push(c);
    }
    
    while(!q.empty())
    {
        int a;
        int b;
        char cur=q.front();
        q.pop();
        if(isdigit(cur))
        {
            num+=cur;
        }
        if(cur=='S')
        {
            
            a=stoi(num);
            b=a;
            num="";
            if(first)
            {
                first=false;
                if(q.front()=='*')
                {
                    answer+=b*2;
                    tmp=b*2;
                }
                else if(q.front()=='#')
                {
                    answer-=b;
                    tmp=-1*b;
                }
                else
                {
                    answer+=b;
                    tmp=b;
                }
            }
            else
            {
                if(!q.empty())
                {
                    if(q.front()=='*')
                    {
                        if(!second)
                        {
                            answer=tmp*2+b*2;
                            second=true;
                        }
                        else
                        {
                            answer+=tmp*2+b*2-tmp;
                        }
                        tmp=b*2;
                    }
                    else if(q.front()=='#')
                    {
                        second=true;
                        answer-=b;
                        tmp=-1*b;
                    }
                    else
                    {
                        second=true;
                        tmp=b;
                        answer+=b;
                    }
                }
                else
                {
                    second=true;
                    answer+=b;
                    tmp=b;
                }
            }
        }
        else if(cur=='D')
        {
            a=stoi(num);
            b=a*a;
            num="";
            if(first)
            {
                 first=false;
                if(q.front()=='*')
                {
                    answer+=b*2;
                    tmp=b*2;
                }
                else if(q.front()=='#')
                {
                    answer-=b;
                    tmp=-1*b;
                }
                else
                {
                    answer+=b;
                    tmp=b;
                }
            }
            else
            {
                if(!q.empty())
                {
                    if(q.front()=='*')
                    {
                        if(!second)
                        {
                            answer=tmp*2+b*2;
                            second=true;
                        }
                        else
                        {
                            answer+=tmp*2+b*2-tmp;
                        }
                        tmp=b*2;
                    }
                    else if(q.front()=='#')
                    {
                        second=true;
                        answer-=b;
                        tmp=-1*b;
                    }
                    else
                    {
                        second=true;
                        tmp=b;
                        answer+=b;
                    }
                }
                else
                {
                    second=true;
                    answer+=b;
                    tmp=b;
                }
            }
        }
        else if(cur=='T')
        {
            a=stoi(num);
            b=a*a*a;
            num="";
            if(first)
            {
                 first=false;
                 if(q.front()=='*')
                {
                    answer+=b*2;
                    tmp=b*2;
                }
                else if(q.front()=='#')
                {
                    answer-=b;
                    tmp=-1*b;
                }
                else
                {
                    answer+=b;
                    tmp=b;
                }
            }
            else
            {
                if(!q.empty())
                {
                    if(q.front()=='*')
                    {
                        if(!second)
                        {
                            answer=tmp*2+b*2;
                            second=true;
                        }
                        else
                        {
                            answer+=tmp*2+b*2-tmp;
                        }
                        tmp=b*2;
                    }
                    else if(q.front()=='#')
                    {
                        second=true;
                        answer-=b;
                        tmp=-1*b;
                    }
                    else
                    {
                        second=true;
                        answer+=b;
                        tmp=b;
                    }
                }
                else
                {
                    second=true;
                    answer+=b;
                    tmp=b;
                }
            }
        }

    }
    return answer;
}
