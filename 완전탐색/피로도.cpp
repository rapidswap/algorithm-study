#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end());

    do {
        int piro = k;
        int cnt = 0;
        for (int i = 0; i < dungeons.size(); i++)
        {
            if (piro >= dungeons[i][0])
            {
                piro -= dungeons[i][1];
                cnt++;
            }

        }
        answer = max(answer, cnt);
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}

//void main()
//{
//    int k = 80;
//    vector<vector<int>> dugenons = { {80,20} ,{50,40},{30,10} };
//
//    int a= solution(k, dugenons);
//    cout << a;
//
//}https://uiop5809.tistory.com/213
