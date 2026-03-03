#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int n = 0;
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int left = 0;
	int right = n - 1;
	int sum = INT_MAX;
	int n1, n2;

	while (left < right)
	{
		int newSum = v[left] + v[right];

		if (abs(newSum) < sum)
		{
			sum = abs(newSum);
			n1 = v[left];
			n2 = v[right];
		}
		
		if (newSum > 0)
		{
			right--;
		}
		else
			left++;
	}

	cout << n1 << " " << n2;

	return 0;
}