#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> v){
    vector<int> vist(v.size());
    queue<int> q;
    
    q.push(1);
    int cnt=0;
    
    while(!q.empty()){
        int cur=q.front(); q.pop();
        if(vist[cur]==1) continue;
        vist[cur]=1;
        cnt++;
        for(int i=0;i<v[cur].size();i++){
            q.push(v[cur][i]);
        }
    }
    
    int cnt2=v.size()-1-cnt;
    return abs(cnt2-cnt);
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 9999;
    
    for(int i=0;i<wires.size();i++){
        vector<vector<int>> v(n+1);
        for(int j=0;j<wires.size();j++){
            if(i==j) continue;
            int st=wires[j][0];
            int ed=wires[j][1];
            v[st].push_back(ed);
            v[ed].push_back(st);
        }
        answer=min(answer,bfs(v));
        v.clear();
    }
    
    return answer;
}
