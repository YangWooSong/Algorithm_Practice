#include <iostream>
#include <vector>
using namespace std;

int n, d, t;
vector<vector<int>> arr;

void Rotate()
{
	vector<vector<int>> tmp = arr;
	int mid = n / 2;

	for (int i = 0; i < n; ++i)
	{
		tmp[i][mid] = arr[i][i];		//가운데 새로  <- 왼쪽 대각이
		tmp[i][n - 1 - i] = arr[i][mid]; //오른쪽 대각선 <- 세로가
		tmp[mid][n-1-i] = arr[i][n - 1 - i]; //가운데 가로 <- 오른쪽 대각이
		tmp[i][i] = arr[mid][i];		//왼쪽 대각선 <- 가로가
		
	}

	arr = tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;

	while (t--)
	{
		cin >> n >> d;
		arr.assign(n, vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		if (d < 0) d += 360;
		int rotateCount = (d % 360) / 45;

		for (int i = 0; i < rotateCount; ++i)
		{
			Rotate();
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}

	}
	return 0;
}