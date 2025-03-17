#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end(),greater<int>());
    
    int boxes=score.size()/m;
    cout<<"boxes: "<<boxes<<'\n';
    int idx=0;
    for(int i=0;i<boxes;i++)
    {
        answer+=score[m+idx-1]*m;
        idx+=m;
    }
    return answer;
}
