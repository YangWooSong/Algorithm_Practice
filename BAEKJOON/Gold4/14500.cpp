#include <iostream>
using namespace std;

int arr[501][501] = {};
bool visited[501][501] = {};
int dir[4][2] = { {1,0} , {-1,0}, {0,1}, {0,-1} };
int answer = 0;

int N, M;

void DFS(int v, int h, int sum, int count)
{
	visited[v][h] = true;
	sum += arr[v][h];

	if (count == 4)
	{
		answer = max(answer, sum);
		visited[v][h] = false;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int newV = v + dir[i][0];
		int newH = h + dir[i][1];

		if (newV >= 0 && newV < N && newH >= 0 && newH < M && visited[newV][newH] == false)
		{
			DFS(newV, newH, sum, count+1);
		}
	}

	visited[v][h] = false;
}

//T자 모양은 따로 검사
void checkT(int v, int h)
{
	int center = arr[v][h];
	int sum = center;
	int cnt = 0;
	int minNum = 1001;

	//십자모양으로 블록 구하고 가장 작은 수 빼기
	for (int i = 0; i < 4; i++)	
	{
		int nV = v + dir[i][0];
		int nH = h + dir[i][1];

		if (nV < 0 || nV >= N || nH < 0 || nH >= M)
			continue;

		cnt++;
		sum += arr[nV][nH];
		minNum = min(minNum, arr[nV][nH]);
	}

	if (cnt < 3) return;

	if (cnt == 4)
		sum -= minNum;

	answer = max(answer, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			DFS(i, j, 0, 1);
			checkT(i, j);
		}
	}

	cout << answer;

	return 0;
}