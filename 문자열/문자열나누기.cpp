#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    int first=0;
    int dif=0;
    stack<char> stk;
    for(char c:s){
        if(stk.empty()){
            stk.push(c);
            first++;
            continue;
        }
        
        if(stk.top() == c){
            first++;
        }
        else{
            dif++;
            if(first == dif){
                answer++;
                first=0;
                dif=0;
                stk.pop();
            }
        }
    }
    if(!stk.empty()) answer++;
    return answer;
}
