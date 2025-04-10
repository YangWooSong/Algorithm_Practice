#include <iostream>
using namespace std;

int stair[301] = {};
int dp[301] = {}; // index계단까지의 최대값
int largest = 0;
int n = 0;

void Step()
{
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	for (int i = 4; i <= n; ++i)
	{
		dp[i] = max(dp[i - 2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> stair[i];
	}

	Step();

	cout << dp[n];

	return 0;
}