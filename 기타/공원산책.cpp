#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int dy = 0, dx = 0;
    for(int i=0;i<park.size();i++){
        size_t pos=park[i].find('S');
        if(pos!=string::npos){
            dy=i;
            dx=pos;
            break;
        }
    }
    cout<<"position: "<< dy << " "<<dx;
    
    for (string route : routes) {
        int move_steps = stoi(route.substr(2));

        if (route[0] == 'N') {
            if(dy-move_steps<0) continue;
            bool dontGo=false;
            int ny=dy;
            for (int i = 0; i < move_steps; i++) {
                ny--;
                if (park[ny][dx] == 'X') {
                    dontGo=true;
                    break;
                }
            }
            if(dontGo) continue;
            else dy=ny;
        }
        
        if (route[0] == 'S') {
            if(dy+move_steps>=park.size()) continue;
            bool dontGo=false;
            int ny=dy;
            for (int i = 0; i < move_steps; i++) {
                ny++;
                if (park[ny][dx] == 'X') {
                    dontGo=true;
                    break;
                }
            }
            if(dontGo) continue;
            else dy=ny;
        }
        
        if (route[0] == 'W') {
            if(dx-move_steps<0) continue;
            bool dontGo=false;
            int nx=dx;
            for (int i = 0; i < move_steps; i++) {
                nx--;
                if (park[dy][nx] == 'X') {
                    dontGo=true;
                    break;
                }
            }
            if(dontGo) continue;
            else dx=nx;
        }
        
        if (route[0] == 'E') {
            if(dx+move_steps>=park[0].size()) continue;
            bool dontGo=false;
            int nx=dx;
            for (int i = 0; i < move_steps; i++) {
                nx++;
                if (park[dy][nx] == 'X') {
                    dontGo=true;
                    break;
                }
            }
            if(dontGo) continue;
            else dx=nx;
        }
    }
    
    answer.push_back(dy);
    answer.push_back(dx);
    return answer;
}
