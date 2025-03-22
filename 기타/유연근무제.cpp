#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i=0;i<timelogs.size();i++){
        int stDay=startday;
        bool event=false;
        for(int logt:timelogs[i]){
            if(stDay==7){
                stDay=1;
                continue;
            }
            else if(stDay==6){
                stDay++;
                continue;
            }
            else{
                
                int agTime=schedules[i]+10;
                if(agTime%100>59){
                    agTime+=40;
                }
                if(agTime>=logt){
                    event=true;
                    stDay++;
                }else{
                    event=false;
                    break;
                }  
            }     
        }
        if(event) answer++;
    }
    return answer;
}
