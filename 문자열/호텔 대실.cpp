#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int getTime(string str){
    return(stoi(str.substr(0,2))*60+stoi(str.substr(3,2)));
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> v;
    for(auto time:book_time){
        v.push_back({getTime(time[0]),getTime(time[1])+10});
    }
    
    priority_queue<int, vector<int>, greater<int>> q;
    sort(v.begin(),v.end());
    
    for(int i=0;i<v.size();i++){
        
        if(!q.empty() && q.top()<=v[i].first){
            q.pop();
        }
        
        q.push({v[i].second});
    }
    
    
    return q.size();
}
