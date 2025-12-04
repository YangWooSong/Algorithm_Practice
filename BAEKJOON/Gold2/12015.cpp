#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> arr;
	vector<int> lis;  // 길이 측정용

	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		int x = arr[i];

		if (lis.empty() || lis.back() < x)
		{
			lis.push_back(x);
		}
		else
		{
			int index = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
			lis[index] = x;
		}
	}

	cout << lis.size() << "\n";


	return 0;
}