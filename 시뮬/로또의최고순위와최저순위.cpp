#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    sort(win_nums.begin(), win_nums.end());
    sort(lottos.begin(), lottos.end());
    
    int cnt = 0;
    int zeros = 0;
    
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            zeros++;
        }
    }

    
    for (int i = 0; i < lottos.size(); i++) {
        if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) {
            cnt++;
        }
    }

    
    int bestRank = 7 - (cnt + zeros);
    int worstRank = 7 - cnt;
    if(worstRank==7)
        worstRank=6;
    if(bestRank==7)
        bestRank=6;
    answer.push_back(bestRank);
    answer.push_back(worstRank);
    
    return answer;
}
