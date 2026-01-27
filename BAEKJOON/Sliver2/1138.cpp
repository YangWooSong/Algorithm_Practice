#include <iostream>
using namespace std;


int arr[1000][1000] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int arr[11] = {};
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	int answer[11] = {};
	for (int i = 0; i < N; ++i)
	{
		int sideCnt = arr[i];

		for (int j = 0; j < N; ++j)
		{
			if(answer[j] == 0)
				sideCnt--;
			if (sideCnt < 0 && answer[j] == 0)
			{
				answer[j] = i + 1;
				break;
			}
		}
	}

	for (int i = 0 ; i < N; ++i)
	{
		cout << answer[i] << " ";
	}
	return 0;
}