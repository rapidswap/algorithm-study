#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long start=1;
    long long M=*max_element(times.begin(),times.end());
    long long end=(M*n);

    while(start<=end)
    {
        long long mid= (start+end)/2;
        long long total=0;
        for(int i=0;i<times.size();i++)
        {
            total+=mid/times[i];
        }
        if(n > total)
        {
            start=mid+1;
        }
        if(n <= total)
        {
            answer=mid;
            end=mid-1;
        }   
    }
    
    return answer;
}
