#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    bool notFound=false;
    for(int i=0;i<targets.size();i++){
        int aa=0;
        for(int j=0;j<targets[i].size();j++){  
            int minCount=INT_MAX;
            for(int k=0;k<keymap.size();k++){
                int cnt=0;
                for(char c: keymap[k]){
                    cnt++;
                    if(c==targets[i][j]){
                        minCount=min(minCount,cnt);
                        break;
                    }
                }
            }
            if(minCount==INT_MAX){
                notFound=true;
                break;
            }
            aa+=minCount;
        }
        if(aa==0 || notFound){
            answer.push_back(-1);
            notFound=false;
        }
        else{
            answer.push_back(aa);
        }
    }
    return answer;
}
