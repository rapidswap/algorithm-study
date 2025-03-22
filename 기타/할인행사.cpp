#include <string>
#include <vector>
#include<iostream>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string,int> wantmap;
    for(int i=0;i<want.size();i++)
    {
        wantmap[want[i]]=number[i];
    }
    
    for(int i=0;i<=discount.size()-10;i++)
    {
        unordered_map<string,int> dismap;
        for(int j=i;j<i+10;j++)
        {
            dismap[discount[j]]++;
        }
        
        bool canbuy=true;
        for(auto a: wantmap)
        {
            if(dismap[a.first]<a.second)
            {
                canbuy=false;
                break;
            }
        }
        if(canbuy)
            answer++;
        dismap.clear();
    }
    
        
    return answer;
}
