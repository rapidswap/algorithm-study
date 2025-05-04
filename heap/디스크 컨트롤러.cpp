#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
    
    sort(jobs.begin(),jobs.end());
    
    
    int diskSize=jobs.size();
    int i=0;
    int curTime=0;
    
    while(1){
        if(i>=diskSize && heap.empty()){
            break;
        }
        
        while(i<diskSize && jobs[i][0]<=curTime){
            heap.push({jobs[i][1],jobs[i][0]});
            i++;
        }
        
        if(!heap.empty()){
            answer+=(curTime-heap.top().second)+heap.top().first;
            curTime+=heap.top().first;
            heap.pop();
        }
        else{
            curTime=jobs[i][0];
        }
        
        
    }
    answer/=diskSize;
    return answer;
}
