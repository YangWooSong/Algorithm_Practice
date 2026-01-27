#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;


int arr[1000][1000] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int p, m;
	cin >> p >> m;
	
	vector<vector<pair<string, int>>> room;
	room.resize(300);

	int roomCnt = 0;

	while (p--)
	{
		int level = 0;
		string name;

		cin >> level >> name;

		if (roomCnt == 0)
		{
			roomCnt++;
			room[0].push_back({ name, level });
		}
		else
		{
			bool isInRoom = false;

			for (int i = 0; i < roomCnt; ++i)
			{
				if (level - room[i][0].second <= 10 && level - room[i][0].second >= -10)
				{
					if (room[i].size() >= m)
					{
						continue;
					}

					room[i].push_back({ name, level });
					isInRoom = true;

					break;
				}
			}

			if (isInRoom == false)
			{
				roomCnt++;
				room[roomCnt-1].push_back({ name, level });
			}
		}
	}

	for (int i = 0; i < roomCnt; ++i)
	{
		if (room[i].size() >= m)
		{
			cout << "Started!\n";
		}
		else
			cout << "Waiting!\n";

		sort(room[i].begin(), room[i].end());

		for (auto a : room[i])//¸â¹ö Ãâ·Â
		{
			cout << a.second << " " << a.first << "\n";
		}
	}
	
	return 0;
}