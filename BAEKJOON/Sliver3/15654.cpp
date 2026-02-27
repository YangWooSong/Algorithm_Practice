#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
int answer[9] = {};

void DFS(int depth, int sIndex)
{
	if (depth == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = sIndex; i < n; ++i)
	{
		if (depth != 0 && answer[depth - 1] == arr[i])
			continue;

		answer[depth] = arr[i];
		DFS(depth + 1, sIndex + 1);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	DFS(0, 0);

	return 0;
}