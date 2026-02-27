#include <iostream>
using namespace std;

int n, m;
int arr[9] = {};

void DFS(int depth, int startNum)
{
	if (depth == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = startNum; i <= n; ++i)
	{
		arr[depth] = i;
		DFS(depth + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	DFS(0, 1);

	return 0;
}