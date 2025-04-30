#include <string>
#include <vector>

using namespace std;
int houseMap[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0;i<puddles.size();i++){
        houseMap[puddles[i][1]][puddles[i][0]]=-1;
    }
    
    houseMap[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a=0;
            int b=0;
            if(houseMap[i][j]==-1) continue;
            
            if(houseMap[i-1][j]!=-1){
                a=houseMap[i-1][j];
            }
            if(houseMap[i][j-1]!=-1){
                b=houseMap[i][j-1];
            }
            
            houseMap[i][j]+= (a+b)%1000000007;
        }
    }
    
    return houseMap[n][m];
}
