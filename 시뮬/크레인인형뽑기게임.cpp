#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> baskets;
    for(int m:moves){
        
        for(int i=0;i<board.size();i++){
            if(board[i][m-1]!=0){
                baskets.push_back(board[i][m-1]);
                board[i][m-1]=0;
                if(baskets.size()>1){
                    if(baskets[baskets.size()-1] == baskets[baskets.size()-2]){
                        baskets.erase(baskets.begin()+baskets.size()-1);
                        baskets.erase(baskets.begin()+baskets.size()-1);
                        answer+=2;
                    }
                }
                break;
            }
        }
    }

    return answer;
}
