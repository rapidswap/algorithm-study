#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int f, s, g, u, d;
int answer = -1;
bool visited[1000001];
int bfs(int start, int target)
{
    queue <pair<int, int>>q;
    q.push({ start,0 });
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == target) return cnt;

        if (cur + u <= f && !visited[cur + u]) {
            q.push({ cur + u, cnt + 1 });
            visited[cur + u] = true;
        }

        if (cur - d >= 1 && !visited[cur - d]) {
            q.push({ cur - d, cnt + 1 });
            visited[cur - d] = true;
        }
    }
    return -1;
}






//void dfs(int start, int target,int cnt) {
//    if (answer == -1 || answer > cnt)
//    {
//        
//        if (start == target)
//        {
//            answer = cnt;
//            return;
//        }
//    }
//    if (s > g)
//    {
//        if (d == 0) return;
//    }
//    if (cnt > f) return;
//    dfs(start + u, target, cnt + 1);
//    dfs(start - d, target, cnt + 1);
//}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> f >> s >> g >> u >> d;
    //dfs(s, g, 0);
    int cnt = bfs(s, g);
    if (cnt == -1) cout << "use the stairs";
    else cout << cnt;
    return 0;
}
