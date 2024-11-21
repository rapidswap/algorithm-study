#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
bool vist[101][101] = { false };
char board[101][101];
char Dboard[101][101];
string rgb[101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> rgb[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rgb[i][j] == 'G')
				Dboard[i][j] = 'R';
			else
				Dboard[i][j] = rgb[i][j];
			board[i][j] = rgb[i][j];
			
		}
	}

	queue<pair<int,int>> q;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vist[i][j])
			{
				vist[i][j] = true;
				q.push({ i,j });
				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && nx < n && !vist[nx][ny] && board[nx][ny] == board[cur.first][cur.second])
						{
							vist[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
				cnt++;
			}
			
		}
	}

	memset(vist, false, sizeof(vist));
	int Dcnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vist[i][j])
			{
				vist[i][j] = true;
				q.push({ i,j });
				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && nx < n && !vist[nx][ny] && Dboard[nx][ny] == Dboard[cur.first][cur.second])
						{
							vist[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
				Dcnt++;
			}

		}
	}
	cout << cnt<<" "<<Dcnt;
	return 0;
}
	
