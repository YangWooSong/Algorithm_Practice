#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//초밥 벨트에 놓인 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	int arr[30001] = {};
	int eatenArr[3001] = {};
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int maxCount = 0;
	int curCount = 0;
	//처음 먹은 범위
	for (int i = 0; i < k; ++i)
	{
		if (eatenArr[arr[i]] == 0)
			curCount++;

		eatenArr[arr[i]]++;
		
	}

	if (eatenArr[c] == 0)	//쿠폰 번호를 먹은 적 없을 때
		maxCount = curCount + 1;

	for (int i = 0; i < n; ++i)
	{
		int outN = arr[i];
		eatenArr[outN]--;
		if (eatenArr[outN] == 0)
			curCount--;

		int newN = arr[(i + k) % n];
		if (eatenArr[newN] == 0)
			curCount++;
		eatenArr[newN]++;

		if (eatenArr[c] == 0)	//쿠폰 번호를 먹은 적 없을 때
			maxCount = max(maxCount, curCount + 1);
		else
			maxCount = max(maxCount, curCount);
	}

	cout << maxCount;

	return 0;
}