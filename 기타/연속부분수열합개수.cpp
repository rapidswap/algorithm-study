#include <bits/stdc++.h>

using namespace std;
set<int> numbers;
vector<int> elements;

void sums(int len)
{
    for(int i=0;i<elements.size();i++)
    {
        int sum=0;
        for(int j=i;j<i+len;j++)
        {
            if(j>=elements.size())  sum+=elements[j-elements.size()];
            else sum+=elements[j];
        }
        numbers.insert(sum);
    }
}

int solution(vector<int> elements) {
    int answer = 0;
    ::elements = elements;
    for(int i=1;i<=elements.size();i++)
    {
        sums(i);   
    }
    answer=numbers.size();
    return answer;
}//https://velog.io/@slow_cosmos/c%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%97%B0%EC%86%8D-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4-%ED%95%A9%EC%9D%98-%EA%B0%9C%EC%88%98
