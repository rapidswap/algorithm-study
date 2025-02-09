#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    
    vector<int> vec{0};
    int answer=0;
    for(int n:ingredient){
        if(vec.back()==1 && n==2){
            vec.back()=12;
        }
        else if(vec.back()==12&&n==3){
            vec.back()=123;
        }
        else if(vec.back()==123&&n==1){
            answer++;
            vec.pop_back();
        }
        else{
            vec.push_back(n);
        }
    }
    return answer;
}
