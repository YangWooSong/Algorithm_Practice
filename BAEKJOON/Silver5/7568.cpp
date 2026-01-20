#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector < pair<int,int> > arr;
	int cnt = 0;
	int answer[51] = {};

	cin >> cnt;
	arr.resize(cnt);


	for (int i = 0; i < cnt; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < cnt; ++i)
	{
		int winnerCnt = 0;

		for (int j = 0; j < cnt; ++j)
		{
			if (j == i)
				continue;

			if (arr[j].first > arr[i].first && arr[j].second > arr[i].second)
				winnerCnt++;
		}

		answer[i] = winnerCnt;
	}

	for (int i = 0; i < cnt; ++i)
	{
		cout << answer[i] + 1 << " ";
	}

	return 0;
}