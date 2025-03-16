#include <string>
#include <vector>

using namespace std;
int dy[] ={0,-1,0,1};
int dx[]={1,0,-1,0};
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    for(int i=0;i<4;i++){
        int ny=h+dy[i];
        int nx=w+dx[i];
        if(ny>=0 && ny<board.size() && nx>=0 && nx<board[0].size()){
            if(board[h][w]==board[ny][nx]){
                answer++;
            }
        }
    }
    return answer;
}
