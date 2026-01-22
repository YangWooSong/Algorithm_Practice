#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//여섯명, 상위 네명 점수 총 합, 동점이면 5번째 점수 비교, 6명 못하면 비교 X , 총 합이 낮은 팀이 우승
	vector<int> constV;
	int raceCnt, playerCnt;
	cin >> raceCnt;

	for (int i = 0; i < raceCnt; ++i)
	{
		cin >> playerCnt;
		constV.resize(playerCnt);

		for (int j = 0; j < playerCnt; ++j)
		{
			cin >> constV[j];
		}

		unordered_map <int, int> m;
		for (int n : constV)
		{
			m[n]++;
		}

		//유효한 점수들로 다시 기록
		unordered_map<int, vector<int>> score;
		int rank = 1;
		for (int n : constV)
		{
			if (m[n] >= 6)
			{
				score[n].push_back(rank);
				rank++;
			}
		}

		int winnerTeam = 0;
		int winnerScore = INT_MAX;
		int winner5th = 0;
		for (auto p : score)
		{
			int sumScore = p.second[0] + p.second[1] + p.second[2] + p.second[3];
			int fifthS = p.second[4];

			if (winnerScore > sumScore)
			{
				winnerTeam = p.first;
				winnerScore = sumScore;
				winner5th = fifthS;
			}
			else if (winnerScore == sumScore)
			{
				if (fifthS < winner5th)
				{
					winnerTeam = p.first;
					winnerScore = sumScore;
					winner5th = fifthS;
				}
			}
		}

		cout << winnerTeam << "\n";
	}

	return 0;
}