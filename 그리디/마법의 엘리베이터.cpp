#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int solution(int storey) {
    int answer=0;
    
    while(storey>0){
        int cur_num=storey%10;
        storey/=10;
        
        if(cur_num>5){
            answer+=(10-cur_num);
            storey++;
        }
        else if(cur_num<5){
            answer+=cur_num;
        }
        else{
            if(storey%10>=5){
                answer+=5;
                storey++;
            }
            else{
                answer+=5;
            }
        }
    }
    return answer;
}
