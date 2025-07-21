#include <iostream>
#include <vector>
using namespace std;

int dp[100001][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    

    for(int i=0;i<4;i++){
        dp[0][i]=land[0][i];
    }
    
    for(int i=1;i<land.size();i++){
        for(int j=0;j<4;j++){
            int pMax=0;
            for(int k=0;k<4;k++){
                if(k==j)continue;
                pMax=max(pMax,dp[i-1][k]);
            }
            dp[i][j]=pMax+land[i][j];
        }
    }
    
    for(int i=0;i<4;i++){
        answer=max(answer,dp[land.size()-1][i]);
    }
  

    return answer;
}
