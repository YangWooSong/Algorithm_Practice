#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int arr[10001] = {};
	int dp[1001] = {};

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int index = 0;
	int maxCount = 0;

	while (index < n)
	{
		if (index == 0)
		{
			dp[index] = 1;
			maxCount = 1;
			index++;
			continue;
		}

		int small_maxCount = 0;
		for (int i = 0; i < index; ++i)
		{
			if (arr[i] < arr[index])
			{
				small_maxCount = max(small_maxCount, dp[i]);
			}
		}

		dp[index] = small_maxCount + 1;
		maxCount = max(maxCount, dp[index]);

		index++;
	}
   
	cout << maxCount;
}