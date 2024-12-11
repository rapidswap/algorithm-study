#include <string>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i=0;i<s.size();i++)
    {
        bool found=false;
        int getMin=INT_MAX;
        for(int j=0;j<=i;j++)
        {
            if(i==j)
                continue;
            if(s[i]==s[j])
            {
                found=true;
                int a=abs(i-j);
                getMin=min(a,getMin);
            }
        }
        if(!found)
            answer.push_back(-1);
        else
            answer.push_back(getMin);
    }
    return answer;
}
