#include <iostream>
using namespace std;


int arr[1000][1000] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	int key = 0;
	int indexX, indexY;
	cin >> cnt;
	cin >> key;

	int dirX[] = {0, 1, 0, -1};
	int dirY[] = { 1, 0 , -1, 0 };


	int x = 0, y = 0, dir = 0;

	for (int i = 0; i < cnt * cnt; ++i)
	{
		if (arr[y][x] == 0)
		{
			arr[y][x] = cnt * cnt - i;

			if (arr[y][x] == key)
			{
				indexY = y;
				indexX = x;
			}
		}

		int nx = x + dirX[dir];
		int ny = y + dirY[dir];

		if (nx < 0 || nx >= cnt || ny < 0 || ny >= cnt || arr[ny][nx] != 0)
		{
			dir = (dir + 1) % 4;
			nx = x + dirX[dir];
			ny = y + dirY[dir];
		}

		x = nx;
		y = ny;
	}

	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << indexY + 1<< " " << indexX + 1;

	return 0;
}