#include <string>
#include <vector>
#include <map>
#include <iostream>
#include<algorithm>
using namespace std;
bool cmp(pair<int,float> a,pair<int,float> b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int player=stages.size();
    vector<pair<int,float>> dif;
    map<int ,int> failed;
    
    for(int n: stages)
    {
        failed[n]++;
    }
    
    for(int i=1;i<=N;i++)
    {
        if(player==0) dif.push_back({i,0});
        else
        {
            dif.push_back({i,(float)failed[i]/(float)player});
            player-=failed[i];
        }
    }
    
    sort(dif.begin(),dif.end(),cmp);
    
    for(auto d:dif)
    {
        answer.push_back(d.first);
    }
    
    return answer;
}
