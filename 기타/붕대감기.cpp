#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int lastAtk= attacks[attacks.size()-1][0];
    int atkTime=0;
    int conTime=0;
    int orgHealths=health;
    for(int i=0;i<=lastAtk;i++){
        
        if(attacks[atkTime][0]==i){
            if(health-attacks[atkTime][1]<=0){
                return -1;
            }
            else{
                conTime=0;
                health-=attacks[atkTime][1];
                atkTime++;

                continue;
            }
        }
        
        
        
        if(health+bandage[1]>orgHealths){
            health=orgHealths;

            conTime++;
            
            if(conTime==bandage[0]){
                conTime=0;
            }
        }
        else{
            health+=bandage[1];

            conTime++;
            
            if(conTime==bandage[0]){
                conTime=0;
                if(health+bandage[2]>orgHealths){
                    health=orgHealths;

                    continue;
                }
                else{
                    health+=bandage[2];

                    continue;
                }
            }
        }
    }
    answer=health;
    return answer;
}
