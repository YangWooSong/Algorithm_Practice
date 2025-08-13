#include <iostream>
#include <vector>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int M, N, K;

void Check(int oriArr[51][51], int newarr[51][51], int y, int x) 
{

	if (oriArr[y][x] == 1)
		newarr[y][x] = 1;

	if (y > 0 && oriArr[y - 1][x] == 1)
	{
		if(newarr[y - 1][x] != 1)
			Check(oriArr, newarr, y - 1, x);
	}
	if (y < N && oriArr[y + 1][x] == 1)
	{	
		if (newarr[y + 1][x] != 1)
			Check(oriArr, newarr, y + 1, x);
	}
	if (x > 0 && oriArr[y][x - 1] == 1)
	{
		if (newarr[y][x - 1] != 1)
			Check(oriArr, newarr, y, x - 1);
	}
	if (x < M && oriArr[y][x + 1] == 1)
	{
		if (newarr[y][x + 1] != 1)
			Check(oriArr, newarr, y, x + 1);
	}
}

int main() {
	Init();
	
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int arr[51][51] = {};
		cin >> N >> M >> K;

		for (int j = 0; j < K; ++j)
		{
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}

		int count = 0;
		int newArr[51][51] = {};

		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (arr[j][k] == 1 && newArr[j][k] == 0)
				{
					Check(arr, newArr, j, k);
					count++;
				}
			}
		}

		cout << count << "\n";
	}

	return 0;
}
