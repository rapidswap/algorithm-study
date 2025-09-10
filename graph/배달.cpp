#include <iostream>
#include <vector>
#include<queue>

using namespace std;
#define INF 2147483647
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
    vector<vector<pair<int,int>>> nodes(N+1);
    vector<int> dist(N+1,INF);
    
    for(auto &r:road){
        int a=r[0];
        int b=r[1];
        int c=r[2];
        nodes[a].push_back({c,b});
        nodes[b].push_back({c,a});
    }
    
    heap.push({0,1});
    dist[1]=0;

    
    while(!heap.empty()){
        auto node=heap.top(); heap.pop();
        
        if(dist[node.second]<node.first) continue;
        
        for(auto a:nodes[node.second]){
            if(dist[a.second]>node.first+a.first){
                dist[a.second]=node.first+a.first;
                heap.push({dist[a.second],a.second});
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        if(dist[i]<=K) answer++;
    }
    return answer;
}
