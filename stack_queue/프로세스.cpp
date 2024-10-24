#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue <int> q;
    int cnt = 1;
    int max = *max_element(priorities.begin(), priorities.end());

    for (int i = 0; i < priorities.size(); i++) {
        q.push(i);
    }

    while (true) {
        int num = q.front();

        if (priorities[num] < max) {
            q.push(num);
            q.pop();
        }
        else {
            if (num == location) {
                return cnt;
            }
            priorities[num] = 0;
            max = *max_element(priorities.begin(), priorities.end());
            cnt++;
            q.pop();
        }
    }
    return answer;
}//https://velog.io/@jimojjing/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4CLv.2-%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4
