#include <iostream>
#include <queue>
using namespace std;

bool visited[1001];
vector<vector<int>> list;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void DFS(int index)
{
	if (visited[index])
		return;

	visited[index] = true;
	for (int i = 0; i < list[index].size(); ++i) {
		DFS(list[index][i]);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	list.resize(n+1);

	for (int i = 0; i < m; ++i)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		list[tmp1].push_back(tmp2);
		list[tmp2].push_back(tmp1);
	}

	int Answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i] == false)
		{
			Answer++;
			DFS(i);
		}
	}

	cout << Answer;

	return 0;
}
