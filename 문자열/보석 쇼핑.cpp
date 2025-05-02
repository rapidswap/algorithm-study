#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string,int> m;
    set<string> uniqueGem(gems.begin(),gems.end());
    
    int Min, start=0,end=0;
    
    for(string str:gems){
        m[str]++;
        if(m.size() == uniqueGem.size()) break;
        end++;
    }
    
    answer[0]=start+1;
    answer[1]=end+1;
    Min=end-start;
    while(end<gems.size()){
        string key=gems[start];
        m[key]--; start++;
        
        if(m[key]==0){
            end++;
            for(;end<gems.size();end++){
                m[gems[end]]++;
                if(key==gems[end]) break;
            }
            if(end==gems.size()) break;
        }
        
        if(Min>end-start){
            Min=end-start;
            answer[0]=start+1;
            answer[1]=end+1;
        }
    }
    return answer;
}
