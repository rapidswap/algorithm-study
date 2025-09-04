#include <string>
#include <vector>
#include <queue>
#include <iostream>

int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int sdist[101][101];
int ldist[101][101];
char board[101][101];

using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    
    fill(sdist[0], sdist[0] + 101 * 101, -1);
    fill(ldist[0], ldist[0] + 101 * 101, -1);
    queue<pair<int,int>> sq;
    queue<pair<int,int>> lq;
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            board[i][j]=maps[i][j];
            if(maps[i][j]=='S'){
                sq.push({i,j});
                sdist[i][j]=0;
            } 
            if(maps[i][j]=='L'){ 
                lq.push({i,j});
                ldist[i][j]=0;
            }
        }
    }
    

    
    while(!sq.empty()){
        auto cur=sq.front();sq.pop();
        
        for(int i=0;i<4;i++){
            int nx=dx[i]+cur.second;
            int ny=dy[i]+cur.first;
            
            if(nx>=maps[0].size() || nx<0 || ny<0 || ny>=maps.size()) continue;
            if(board[ny][nx]=='X') continue;
            if(sdist[ny][nx] > -1) continue;
            
            sdist[ny][nx]=sdist[cur.first][cur.second]+1;
            sq.push({ny,nx});
            if(board[ny][nx]=='L'){
                answer+=sdist[ny][nx];
                break;
            }
        }
    }
    if(answer==0) return -1;
    
    
    int newanswer=answer;
     while(!lq.empty()){
        auto cur=lq.front();lq.pop();
        
        for(int i=0;i<4;i++){
            int nx=dx[i]+cur.second;
            int ny=dy[i]+cur.first;
            
            if(nx>=maps[0].size() || nx<0 || ny<0 || ny>=maps.size()) continue;
            if(board[ny][nx]=='X') continue;
            if(ldist[ny][nx] > -1) continue;
            
            ldist[ny][nx]=ldist[cur.first][cur.second]+1;
            lq.push({ny,nx});
            if(board[ny][nx]=='E'){
                answer+=ldist[ny][nx];
                break;
            }
        }
    }
    
    if(newanswer==answer) return -1;
    
    return answer;
}
