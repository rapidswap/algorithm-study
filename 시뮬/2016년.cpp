#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int day=0;
    if(a>1)
    {
        for(int i=1;i<a;i++)
        {
            if(i==2)
            {
                day+=29;
                continue;
            }
            if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
                day+=31;
            else
            {
                day+=30;
            }
        }
    }
    day+=b;
    day=day%7;
    
    if(day==0)
    {
        answer="THU";
    }
    else if(day==1)
    {
        answer="FRI";
    }
    else if(day==2)
    {
        answer="SAT";
    }
    else if(day==3)
    {
        answer="SUN";
    }
    else if(day==4)
    {
        answer="MON";
    }
    else if(day==5)
    {
        answer="TUE";
    }
    else if(day==6)
    {
        answer="WED";
    }
    
    return answer;
}
