#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<edge.size();i++){
        int from = edge[i][0];
        int to=edge[i][1];
        
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    queue<int> q;
    vector<int>dist(n+1,-1);
    q.push(1);
    dist[1]=0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next : graph[cur]){
            if(dist[next]==-1){
                dist[next]=dist[cur]+1;
                q.push(next);
            }
        }
    }
    int max = *max_element(dist.begin(),dist.end());
    for(int i =0;i<dist.size(); i++){
        if(dist[i] == max){
            answer++;

        }
    }
    return answer;
}//https://velog.io/@lsh/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B0%80%EC%9E%A5-%EB%A8%BC-%EB%85%B8%EB%93%9C
