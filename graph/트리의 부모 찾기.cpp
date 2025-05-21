#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int n;
vector<vector<int>> node;
int p[100001];


void dfs(int cur) {
    for (int next : node[cur]) {
        if (p[cur] == next) continue;
        p[next] = cur;
        dfs(next);
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    cin >> n;
    node.resize(n + 1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b); 
        node[b].push_back(a);
    }

    dfs(1);
    for (int i = 2; i <= n; i++) cout << p[i]<<'\n';
    return 0;
}
