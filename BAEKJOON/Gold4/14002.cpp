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
	vector<int> pos(n);  // arr[i]가 lis의 몇 번째 위치인지 기록

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
			pos[i] = lis.size() - 1;
		}
		else
		{
			int index = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
			lis[index] = x;
			pos[i] = index;
		}
	}

	cout << lis.size() << "\n";

	vector<int> answer(lis.size());
	int target = lis.size() - 1;
	for (int i = n - 1; i >= 0; --i)
	{
		if (pos[i] == target)
		{
			answer[target] = arr[i];
			target--;
		}

		if (target < 0)
			break;
	}

	for (int x : answer)
		cout << x << " ";

	return 0;
}