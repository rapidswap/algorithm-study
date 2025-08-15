#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <queue>
using namespace std;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string,string>> events;
    unordered_map<string,string> userList;
    
    
    for(auto user:record){
        stringstream ss;
        ss.str(user);
        string status,uid,name;
        ss>>status>>uid>>name;
        
        if(status=="Enter" || status=="Change"){
            userList[uid]=name;
        }
        
        if(status=="Enter" || status=="Leave"){
            events.push({uid,status});
        }
    }
    
    while(!events.empty()){
        auto event=events.front();events.pop();
        
        if(event.second=="Enter"){
            answer.push_back(userList[event.first]+"님이 들어왔습니다.");
        }
        else if(event.second=="Leave"){
            answer.push_back(userList[event.first]+"님이 나갔습니다.");
        }
    }
    
    return answer;
}
