#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	int cowArr[11] = {};
	map<int, int> cowMap;

	cin >> cnt;

	for (int i = 0; i < cnt; ++i)
	{
		int index = 0;
		int road = 0;

		cin >> index >> road;

		if (cowMap.find(index) != cowMap.end())
		{
			if(road != cowMap[index])
			{
				cowMap[index] = road;
				cowArr[index]++;
			}
		}
		else
			cowMap.insert({ index, road });
	}

	int answer = 0;
	for (int i = 0; i < 11; ++i)
	{
		answer += cowArr[i];
	}

	cout << answer;

	return 0;
}