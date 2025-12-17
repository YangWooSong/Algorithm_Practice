#include <iostream>
#include <queue>
using namespace std;

// 상하좌우 이동을 위한 배열
int dx[] = { 0, 0, 1, -1 }; // x축 이동 (가로)
int dy[] = { 1, -1, 0, 0 }; // y축 이동 (세로)

// 큐에 넣을 좌표를 구조체로 정의 (y, x)
struct Pos {
	int y, x;
};

int m, n;
vector<vector<int>> box;
queue<Pos> q;

void BFS()
{
	while (q.empty() == false)
	{
		Pos current = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = current.y + dy[i];
			int nx = current.x + dx[i];

			// 1. 상자 범위를 벗어나는지 확인
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;

			if (box[ny][nx] == 0)
			{
				// 토마토를 익게 하고 (날짜 갱신)
				box[ny][nx] = box[current.y][current.x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	box.resize(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}

	BFS();
	
	bool all_ripped = true;
	int max_day = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (box[i][j] == 0)
			{
				all_ripped = false;
			}

			max_day = max(max_day, box[i][j]);
		}
	}

	if (all_ripped == false)
		cout << -1;
	else
		cout << max_day - 1;

	return 0;
}