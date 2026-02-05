#include <iostream>
#include <queue>
using namespace std;


int m;//가로
int n; //세로
int h; //높이
int arr[100][100][100] = {};
int answer = 0;


struct tomato
{
	int index_h;
	int index_n;
	int index_m;
};

void BFS()
{
	queue<tomato> q;
	int unRipped = 0;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (arr[i][j][k] == 1)
				{
					tomato t = { i,j,k };
					q.push(t);
				}
				else if (arr[i][j][k] == 0)
				{
					unRipped++;
				}
			}
		}
	}

	//처음부터 못 익거나 다 익은 경우
	if (unRipped == 0)
		return;

	while (!q.empty())
	{
		tomato t = q.front();
		q.pop();

		int curDate = arr[t.index_h][t.index_n][t.index_m];

		if (t.index_h - 1 >= 0 && arr[t.index_h - 1][t.index_n][t.index_m] == 0)
		{
			//tomato tmp = { t.index_h - 1 ,t.index_n ,t.index_m };
			q.push({ t.index_h - 1 ,t.index_n ,t.index_m });
			arr[t.index_h - 1][t.index_n][t.index_m] = curDate+1;
		}
		if (t.index_h + 1 < h && arr[t.index_h + 1][t.index_n][t.index_m] == 0)
		{
			q.push({ t.index_h + 1 ,t.index_n ,t.index_m });
			arr[t.index_h + 1][t.index_n][t.index_m] = curDate + 1;
		}
		if (t.index_n + 1 < n && arr[t.index_h ][t.index_n + 1][t.index_m] == 0)
		{
			q.push({ t.index_h ,t.index_n + 1 ,t.index_m });
			arr[t.index_h][t.index_n + 1][t.index_m] = curDate + 1;
		}
		if (t.index_n - 1 >= 0 && arr[t.index_h][t.index_n - 1][t.index_m] == 0)
		{
			q.push({ t.index_h ,t.index_n - 1 ,t.index_m });
			arr[t.index_h][t.index_n - 1][t.index_m] = curDate + 1;
		}
		if (t.index_m - 1 >= 0 && arr[t.index_h][t.index_n ][t.index_m - 1] == 0)
		{
			q.push({ t.index_h ,t.index_n ,t.index_m - 1 });
			arr[t.index_h][t.index_n][t.index_m - 1] = curDate + 1;
		}
		if (t.index_m + 1 < m && arr[t.index_h][t.index_n][t.index_m + 1] == 0)
		{
			q.push({ t.index_h ,t.index_n ,t.index_m + 1 });
			arr[t.index_h][t.index_n][t.index_m + 1] = curDate + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> h;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				cin >> arr[i][j][k];
			}
		}
	}

	BFS();

	int maxDay = 0;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (arr[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
				maxDay = max(maxDay, arr[i][j][k]);
			}
		}
	}

	cout << maxDay - 1;

	return 0;
}