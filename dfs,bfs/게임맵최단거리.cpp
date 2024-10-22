#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool vist[100][100];
int dist[100][100];
queue<pair<int, int>> q;

int solution(vector<vector<int> > maps)
{
	int answer = 0;
	int ns = maps.size();
	int ms = maps[0].size();
	memset(dist, -1, sizeof(dist));
	q.push({ 0,0 });
	dist[0][0] = 1;
	vist[0][0] = 1;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		if (cur.first == ns - 1 && cur.second == ms - 1)
			return dist[ns - 1][ms - 1];
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.second + dx[dir];
			int ny = cur.first + dy[dir];
			if (nx < 0 || ny < 0 || nx >= ms || ny >= ns) continue;
			if (vist[ny][nx] || maps[ny][nx] == 0 || dist[ny][nx] != -1) continue;
			q.push({ ny, nx });
			vist[ny][nx];
			dist[ny][nx] = dist[cur.first][cur.second] + 1;
		}
	}
	if (dist[ns - 1][ms - 1] == -1) answer = -1;
	else answer = dist[ns-1][ms-1];
	return answer;
} //https://velog.io/@rhkswls98/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-C-%EA%B2%8C%EC%9E%84-%EB%A7%B5-%EC%B5%9C%EB%8B%A8%EA%B1%B0%EB%A6%AC
