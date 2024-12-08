#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int dp[500][500];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();i++)
    {
        for(int j=0;j<triangle[i].size();j++)
        {
            if(j==0)
            {
                dp[i][j]=triangle[i][j]+dp[i-1][j];
                continue;
            }
            else if(j==triangle[i].size()-1)
            {
                dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                continue;
            }
            else
            {
                dp[i][j]=max(triangle[i][j]+dp[i-1][j-1],triangle[i][j]+dp[i-1][j]);
            }
                    
        }
    }
    int getMax=0;
    for(int i=0;i<triangle[triangle.size()-1].size();i++)
    {
        cout<<dp[triangle.size()-1][i]<<"\n";
        if(getMax<dp[triangle.size()-1][i])
            getMax=dp[triangle.size()-1][i];
    }
    answer=getMax;
    return answer;
}
