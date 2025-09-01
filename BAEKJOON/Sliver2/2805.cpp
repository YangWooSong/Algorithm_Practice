#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}



int main() {
	Init();
	int N, M, H = 0;
	cin >> N >> M;

	vector<int> arr;
	arr.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	//길이 기준
	int start = 0;
	int end = arr[N - 1];
	int mid = (start + end) / 2;
	while (start <= end)
	{
		mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] >= mid)
				sum += arr[i] - mid;
		}

		if (sum < M)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
			if (H < mid)
				H = mid;
		}
	}

	cout << H;

	return 0;
}
