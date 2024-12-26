#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
    if (n==1) return false;
    if(n==2) return true;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int numLen=nums.size();
    for(int i=0;i<numLen;i++)
    {
        for(int j=i+1;j<numLen;j++)
        {
            for(int k=j+1;k<numLen;k++)
            {
                int a=nums[i]+nums[j]+nums[k];
                if(isPrime(a))
                    answer++;                      
            }
        }
    }
    

    return answer;
}
