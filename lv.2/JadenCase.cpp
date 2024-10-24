#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst=true;
    for(int i=0;i<s.length();i++){
        
        
        if(isFirst){
            if(isalpha(s[i])&& islower(s[i])){
                s[i]=toupper(s[i]);
                isFirst=false;
            }else{
                isFirst=false;
            }
        }else{
            if(isupper(s[i])) s[i]=tolower(s[i]);
        }
        if(s[i]==' ') isFirst=true;
    }
    
    return s;
}
