#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n>0){
        int a=n%3;
        n/=3;
        
        if(a==0){
            answer="4"+answer;
            n-=1;
        }
        else
            answer=to_string(a)+answer;
        
    }
    return answer;
}
