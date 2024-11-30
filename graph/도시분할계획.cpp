#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<limits.h>
#include<cmath>
#include<algorithm>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int manyCost = INT_MIN;
    int N, M;
    cin >> N >> M;

    vector<bool> vst(N + 1, false);
    vector<vector<pair<int, int>>> nodes(N+1);
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    int answer = 0;

    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({ c,b });
        nodes[b].push_back({ c,a });
    }

    heap.push({ 0,1 });

    while (!heap.empty())
    {
        auto node = heap.top();
        heap.pop();

        if (!vst[node.second])
        {
            vst[node.second] = true;
            manyCost = max(manyCost, node.first);
            answer += node.first;
            for (auto a : nodes[node.second])
            {
                heap.push({ a.first,a.second });

            }
        }
    }

    cout << answer-manyCost;


   
    return 0;
}
