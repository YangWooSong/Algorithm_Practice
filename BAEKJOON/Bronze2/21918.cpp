#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int bolb[4000] = {};
	int bCnt = 0;
	int order_Cnt = 0;

	cin >> bCnt;
	cin >> order_Cnt;

	for (int i = 0; i < bCnt; ++i)
	{
		cin >> bolb[i];
	}

	for (int i = 0; i < order_Cnt; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			bolb[b - 1] = c;
		}
		else if (a == 2)
		{
			for (int j = b - 1; j < c; ++j)
			{
				if (bolb[j] == 0)
					bolb[j] = 1;
				else
					bolb[j] = 0;
			}
		}
		else if (a == 3)
		{
			for (int j = b - 1; j < c; ++j)
			{
				bolb[j] = 0;
			}
		}
		else if (a == 4)
		{
			for (int j = b - 1; j < c; ++j)
			{
				bolb[j] = 1;
			}
		}
	}

	for (int i = 0; i < bCnt; ++i)
	{
		cout << bolb[i] << " ";
	}

	return 0;
}