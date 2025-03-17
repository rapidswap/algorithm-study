#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minY=51,maxY=-1;
    int minX=51,maxX=-1;
    
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[0].size();j++){
            if(wallpaper[i][j]=='#'){
                minY=min(minY,i);
                maxY=max(maxY,i+1);
                minX=min(minX,j);
                maxX=max(maxX,j+1);
            }
        }
    }
    answer.push_back(minY);
    answer.push_back(minX);
    answer.push_back(maxY);
    answer.push_back(maxX);
    
    return answer;
}
