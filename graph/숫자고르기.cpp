#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;

int N;
int graph[101];
bool vist[101];
bool finished[101];
vector<int> answer;

void dfs(int curNode) {
    vist[curNode] = true;

    int nextNode = graph[curNode];

    if (!vist[nextNode]) {
        dfs(nextNode);
    }

    else if (!finished[nextNode]) {
        int temp = nextNode;
        while (temp != curNode) {
            answer.push_back(temp);
            temp = graph[temp];
        }
        answer.push_back(curNode);
    }
    finished[curNode] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> graph[i];
    }

    for (int i = 1; i <= N; i++) {
        if (!vist[i]) {
            dfs(i);
        }
    }
  
    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;
    for (int num : answer) {
        cout << num << endl;
    }


    return 0;
}
