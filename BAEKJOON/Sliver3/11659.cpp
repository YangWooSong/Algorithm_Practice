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
	
	int numCount, tc;
	cin >> numCount >> tc;

	vector<int> arr;
	arr.resize(numCount);

	for (int i = 0; i < numCount; ++i)
	{
		int tmp;
		cin >> tmp;

		if (i != 0)
		{
			arr[i] = arr[i - 1] + tmp;
		}
		else
			arr[0] = tmp;
	}

	for (int i = 0; i < tc; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;

		int sum = 0;
		if (n1 - 2 > 0)
		{
			sum = arr[n2 - 1] - arr[n1 - 2];
		}
		else
			sum = arr[n2 - 1];
		cout << sum << "\n";
	}

	return 0;
}
