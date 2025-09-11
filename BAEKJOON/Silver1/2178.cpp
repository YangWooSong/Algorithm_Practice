#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[101][101] = {};
bool visited[101][101] = {};
int count_arr[101][101] = {};

void Init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void BFS(int _n, int _m)
{
	queue<pair<int, int>> q;
	q.push(make_pair(_n, _m));
	visited[_n][_m] = true;
	count_arr[_n][_m] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int count = count_arr[x][y];
		q.pop();

		if (x == n-1 && y == m-1)
			cout << count;

		if ((x - 1 >= 0 && arr[x - 1][y] == 1) && visited[x - 1][y] == false)
		{
			q.push(make_pair(x - 1, y));
			visited[x - 1][y] = true;
			count_arr[x - 1][y] = count + 1;
		}

		if ((x + 1 < n && arr[x + 1][y] == 1) && visited[x + 1][y] == false)
		{
			q.push(make_pair(x + 1, y));
			visited[x + 1][y] = true;
			count_arr[x + 1][y] = count + 1;
		}

		if ((y + 1 < m && arr[x ][y + 1] == 1) && visited[x][y+1] == false)
		{
			q.push(make_pair(x , y + 1));
			visited[x][y + 1] = true;
			count_arr[x ][y + 1] = count + 1;
		}

		if ((y - 1 >= 0 && arr[x][y - 1] == 1) && visited[x][y - 1] == false)
		{
			q.push(make_pair(x, y - 1));
			visited[x][y - 1] = true;
			count_arr[x][y - 1] = count + 1;
		}
	}
}

int main()
{
	Init();

	cin >> n >> m;

	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			arr[i][j] = str[j] - '0';
		}
	}

	BFS(0, 0);


	return 0;
}