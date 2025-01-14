#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(char c:s){
        bool skipFound=false;
        int idx=0;
        while(idx<index){
            c++;
            if(c>'z'){
                c='a'+(c-'z'-1);
            }
            for(char sk:skip){
                if(c==sk){
                    skipFound=true;
                    break;
                }
            }
            if(skipFound){
                skipFound=false;
                continue;
            }
            idx++;
        }
        
        answer+=c;
    }
        
    
    return answer;
}
