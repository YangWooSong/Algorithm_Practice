#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	char cArr[101][101] = {};
	int aArr[101][101] = {};

	int w, h;
	cin >> h >> w;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> cArr[i][j];
		}
	}


	for (int i = 0; i < h; ++i)
	{
		bool isCloud = false;
		int CloudCnt = 0;

		for (int j = 0; j < w; ++j)
		{
			if (cArr[i][j] == 'c')
			{
				CloudCnt = 0;
				isCloud = true;
			}
			else
			{
				if (isCloud)
					CloudCnt++;
			}

			if (isCloud == false)
				aArr[i][j] = -1;
			else
			{
				aArr[i][j] = CloudCnt;
			}
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << aArr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}