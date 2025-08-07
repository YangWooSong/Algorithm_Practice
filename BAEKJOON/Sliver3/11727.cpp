#include <iostream>
#include <vector>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	Init();
	
	int n = 0;
	cin >> n;

	vector<long long> dp;
	dp.resize(1001);
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}
