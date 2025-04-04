#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> time;
	for (int a,i = 0; i < n; ++i)
	{
		cin >> a;
		time.push_back(a);
	}

	sort(time.begin(), time.end());

	int total = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			total += time[j];
		}
	}

	cout << total;
	return 0;
}