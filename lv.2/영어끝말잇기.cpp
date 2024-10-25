#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    queue<string> q;
    int cnt=0;
    int allcnt=1;

    for(auto str : words){
        if(q.empty()){
            q.push(str);
            cnt++;

            continue;
        }
        if(q.size()%n==0)
            allcnt++;
        bool isDuplicate = false;
        queue<string> tempQueue = q;
        while (!tempQueue.empty()) {
            if (tempQueue.front() == str) {
                isDuplicate = true;
                break;
            }
            tempQueue.pop();
        }

        if(q.back().back()==str.front() && q.back() != str && !isDuplicate){
            q.push(str);
            cnt++;
        }else{
            cnt++;
            
            if(cnt%n ==0)
                answer.push_back(n);
            else
                answer.push_back(cnt%n);
            answer.push_back(allcnt);
            
            return answer;
        }

    }

    return {0,0};
}
