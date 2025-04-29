#include <string>
#include <vector>
#include <map>
using namespace std;

string AEIOU="AEIOU";
int answer=-1;
int cnt=0;
void dfs(string w, string org){
    
    if(answer==cnt){
        return;
    }
    
    for(int i=0;i<5;i++){
        cnt++;
        w+=AEIOU[i];
        if(w==org){
            answer=cnt;
            return;
        }
        
        if(w.size()<5)
            dfs(w,org);
        
        w.pop_back();
    }
}
int solution(string word) {
    dfs("",word);

    return answer;
}
