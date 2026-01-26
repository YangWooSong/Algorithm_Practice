#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	cin >> cnt;

	int teamN = 0;
	string time;

	int teamOneGoal = 0;
	int teamTwoGoal = 0;
	int beforeWinTime = 0;
	int teamOneWinTime = 0;
	int teamTwoWinTime = 0;
	int min = 0;
	int second = 0;
	while (cnt--)
	{
	
		cin >> teamN >> time;

		min = stoi(time.substr(0, 2));
		second = stoi(time.substr(3, 2));

		if (teamOneGoal > teamTwoGoal)
		{
			teamOneWinTime += (min * 60 + second) - beforeWinTime;
		}
		else if (teamOneGoal < teamTwoGoal)
		{
			teamTwoWinTime += (min * 60 + second) - beforeWinTime;
			
		}

		if (teamN == 1)
			teamOneGoal++;
		else
			teamTwoGoal++;

		beforeWinTime = (min * 60 + second);
	}

	if (teamOneGoal > teamTwoGoal)
	{
		teamOneWinTime += (48 * 60 + 0) - beforeWinTime;
	}
	else if (teamOneGoal < teamTwoGoal)
	{
		teamTwoWinTime += (48 * 60 + 0) - beforeWinTime;
	}

	printf("%02d:%02d\n", teamOneWinTime / 60, teamOneWinTime % 60);
	printf("%02d:%02d\n", teamTwoWinTime / 60, teamTwoWinTime % 60);
	return 0;
}