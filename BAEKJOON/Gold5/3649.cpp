#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long x;
	int n;
	

	while (cin >> x)
	{
		cin >> n;
		x *= 10000000;

		vector<long long> v;

		for (int i = 0; i < n; ++i)
		{
			long long tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		sort(v.begin(), v.end());

		int left = 0;
		int right = n - 1;
		long long a1 = { -1 };
		long long a2 = { -1 };

		while (left < right)
		{
			long long sum = v[left] + v[right];

			if (sum == x)
			{
				if (a1 == -1)	//처음 찾았을 때
				{
					a1 = v[left];
					a2 = v[right];
					break;
				}
			}
			else if (sum > x)
			{
				right--;
			}
			else
			{
				left++;
			}
		}

		if (a1 != -1)
		{
			cout << "yes " << a1 << " " << a2;
		}
		else
		{
			cout << "danger";
		}
	}
	
	return 0;
}