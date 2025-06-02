#include <iostream>
#include <queue>
#include <vector> 
#include <cstring>
using namespace std;

int N, M;
bool vist[101];
int dist[101];
vector<pair<int, int>> ladder;
vector<pair<int, int>> snake;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        ladder.push_back({ a,b });
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        snake.push_back({ a,b });
    }

    queue<int> q;
    q.push(1);
    vist[1] = true;
    dist[1] = 0;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int i = 1; i <= 6; i++) {
            int mv = cur + i;
            if (mv > 100) continue;
            //if (dist[mv] > 0 || vist[mv]) continue;
            
            for (int lad = 0; lad < ladder.size(); lad++) {
                if (mv == ladder[lad].first) {
                    mv = ladder[lad].second;
                    break;
                }
            }
            for (int snk = 0; snk < snake.size(); snk++) {
                if (mv == snake[snk].first) {
                    mv = snake[snk].second;
                    break;
                }
            }
            if (vist[mv]) continue;
            q.push(mv);
            vist[mv] = true;
            dist[mv] = dist[cur] + 1;
        }
    }

    cout << dist[100];
    return 0;
}
