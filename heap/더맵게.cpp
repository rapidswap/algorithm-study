#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>,greater<int>> q;
    for(int sco : scoville)
    {
        q.push(sco);
    }
    int min=q.top();
    while(min<K)
    {
        if(q.size()==1)
        {
            answer=-1;
            break;
        }
        answer++;
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        q.push(a+(b*2));
        min=q.top();
    }
    return answer;
}
