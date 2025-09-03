#include <iostream>
#include <queue>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int n, m, b;
	int arr[500][500] = {};

	cin >> n >> m >> b;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int time = 64000000;
	int height = 0;
	for (int h = 0; h <= 256; ++h)
	{
		int tmp_time = 0;
		int tmp_b = b;
		bool isAble = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (arr[i][j] < h)
				{
					int height_difference = h - arr[i][j];
					tmp_b -= height_difference;
					tmp_time += height_difference;
					
				}
				else if (arr[i][j] > h)
				{
					int height_difference = arr[i][j] -  h;
					tmp_b += height_difference;
					tmp_time += height_difference * 2;
				}
			}
		}

		if (tmp_b >= 0)
		{
			if (tmp_time <= time)
			{
				if (time == tmp_time)
					height = max(height, h);
				else
					height = h;

				time = tmp_time;
				
			}
		}
	}

	cout << time << " " << height ;

	return 0;
}
