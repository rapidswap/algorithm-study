#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> nodes(N + 1);
    vector<bool> visit(N + 1, false);

    for (int i = 0; i < M + 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({ c, b });
        nodes[b].push_back({ c, a });
    }


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({ 1, 0 });

    int minAnswer = 0;
    fill(visit.begin(), visit.end(), false);

    while (!minHeap.empty()) {
        auto minNode = minHeap.top();
        minHeap.pop();

        if (!visit[minNode.second]) {
            visit[minNode.second] = true;



                if (minNode.first == 0) {  
                    minAnswer += 1; 
                }
            

            for (auto edge : nodes[minNode.second]) {
                if (!visit[edge.second]) {
                    minHeap.push({ edge.first, edge.second });
                }
            }
        }
    }

    priority_queue<pair<int, int>> maxHeap;
    maxHeap.push({ 1, 0 });

    int maxAnswer = 0;
    fill(visit.begin(), visit.end(), false);

    while (!maxHeap.empty()) {
        auto maxNode = maxHeap.top();
        maxHeap.pop();

        if (!visit[maxNode.second]) {
            visit[maxNode.second] = true;


                if (maxNode.first == 0) {  
                    maxAnswer += 1;  
                }
            

            for (auto edge : nodes[maxNode.second]) {
                if (!visit[edge.second]) {
                    maxHeap.push({ edge.first, edge.second });
                }
            }
        }
    }

    maxAnswer = maxAnswer * maxAnswer;
    minAnswer = minAnswer * minAnswer;

    cout << minAnswer - maxAnswer << "\n";

    return 0;
}
