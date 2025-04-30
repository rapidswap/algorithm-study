#include <string>
#include <iostream>
using namespace std;

class point{
    public:
    bool right;
    bool left;
    bool up;
    bool down;
};

point bMap[11][11];

int solution(string dirs) {
    int answer = 0;
    int x=5;
    int y=5;
    for(char c: dirs){
        switch(c){
            case 'U':
            if(y+1<11){
                y++;
                if(!bMap[y][x].down){
                    bMap[y][x].down=true;
                    bMap[y-1][x].up=true;
                    answer++;
                }
            }
            break;

            case 'D':
            if(y-1>-1){
                y--;
                if(!bMap[y][x].up){
                    bMap[y][x].up=true;
                    bMap[y+1][x].down=true;
                    answer++;
                }
            }
            break;

            case 'R':
            if(x+1<11){
                x++;
                if(!bMap[y][x].left){
                    bMap[y][x].left=true;
                    bMap[y][x-1].right=true;
                    answer++;
                }
            }
            break;

            case 'L':
            if(x-1>-1){
                x--;
                if(!bMap[y][x].right){
                    bMap[y][x].right=true;
                    bMap[y][x+1].left=true;
                    answer++;
                }
            }
            break;
        }
    }
    return answer;
}
