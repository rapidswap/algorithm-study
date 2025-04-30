#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> mts;
    vector<int> answer;
    for(string str:operations){
        if(str == "D 1"){
            if(mts.empty()) continue;
            
            auto it=mts.end();
            --it;
            mts.erase(it);
        }
        
        if(str == "D -1"){
            if(mts.empty()) continue;
            mts.erase(mts.begin());
        }
        
        if(str[0]=='I'){
            
            int num=stoi(str.substr(2));
            mts.insert(num);
        }
    }
    
    if(mts.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*mts.rbegin());
        answer.push_back(*mts.begin());
    }
    return answer;
}
