#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>s){
        answer.push_back(-1);
        return answer;
    } 
    int a= s/n;
    int b= s%n;
    
    for(int i=0;i<n;i++){
            answer.push_back(a);
    }
    
    for(int i=n-1;i>=n-b;i--){
        answer[i]++;
    }
    
    return answer;
}
