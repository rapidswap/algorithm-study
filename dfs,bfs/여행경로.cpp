#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool vist[10000];
bool isEnd = false;
int cnt = 0;
vector<string> answer;

void dfs(string start, vector<vector<string>> tickets)
{
    if (cnt == tickets.size()) isEnd = true;
    answer.push_back(start);
    for (int i = 0; i < tickets.size(); i++)
    {
        if (!vist[i] && tickets[i][0] == start)
        {
            vist[i] = true;
            cnt++;
            dfs(tickets[i][1], tickets);

            if (!isEnd)
            {
                answer.pop_back();
                vist[i] = false;
            }
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets);
    return answer; //https://gyyeom.tistory.com/43
}
