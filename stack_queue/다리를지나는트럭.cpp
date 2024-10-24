#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue <int> q;
    int idx=0;
    int sum=0;
    
    
    while(true){
        if(idx == truck_weights.size()){
            answer+=bridge_length;
            break;
        }
        answer++;
        int wei = truck_weights[idx];
        if(q.size() == bridge_length){
            sum-=q.front();
            q.pop();
        }
        
        if(sum+wei <= weight){
            sum+=wei;
            q.push(wei);
            idx++;
        }else{
            q.push(0);
        }
        
    }
    return answer;
}//https://velog.io/@qhsh866/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4Level2-%EB%8B%A4%EB%A6%AC%EB%A5%BC-%EC%A7%80%EB%82%98%EB%8A%94-%ED%8A%B8%EB%9F%AD-C
