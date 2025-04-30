#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> qWorks;
    for(int n: works){
        qWorks.push(n);
    }
    
    while(n--){
        int work=qWorks.top();
        if(work-1 < 0) continue;
        qWorks.pop();
        work--;
        qWorks.push(work);  
    }
    
    while(!qWorks.empty()){
        answer+=qWorks.top() * qWorks.top();
        qWorks.pop();
    }
    return answer;
}
