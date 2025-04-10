#include <iostream>
using namespace std;

void Count(int num) {
	int dp[12] = { 0 };

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= num; ++i)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	cout << dp[num] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int a,i = 0; i < t; ++i)
	{
		cin >> a;
		Count(a);
	}
	return 0;
}