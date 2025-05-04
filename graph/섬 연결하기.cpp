#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<pair<int,int>>> nodes(n);
    vector<bool> vist(n,false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    
    for(int i=0;i<costs.size();i++){
        int a,b,c;
        a=costs[i][0];
        b=costs[i][1];
        c=costs[i][2];
        nodes[a].push_back({c,b});
        nodes[b].push_back({c,a});
    }
    
    heap.push({0,0});
    
    while(!heap.empty()){
        auto node=heap.top();
        heap.pop();
        if(!vist[node.second]){
            answer+=node.first;
            vist[node.second]=true;
            for(auto a: nodes[node.second]){
                heap.push({a.first,a.second});
            }
        }
    }
    
    
    return answer;
}
