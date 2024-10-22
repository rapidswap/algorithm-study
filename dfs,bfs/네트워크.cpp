#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(int n, int com, vector<vector<int>> &computers, vector<bool> &vist)
{
    vist[com] = true;
    for (int i = 0; i < n; i++)
    {
        if (i != com && computers[i][com] == 1 && vist[i] == false)
        {
            dfs(n, i, computers, vist);
            
        }

    }
}

int solution(int n, vector<vector<int>> computers) {

    vector<bool> vist(n,false);


    for (int i = 0; i < n; i++) {
        if (vist[i] == false) {
            dfs(n, i, computers, vist);
            answer++;
        }
    }
    return answer;
}//https://velog.io/@soorim_yoon/DFSBFS-%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-Level-3
