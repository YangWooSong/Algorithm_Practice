#include <iostream>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	
	int n = 0;
	int arr[200001] = {};
	int frequency[10] = {};
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int l = 0, r = 0, count = 1, answer = 0;
	frequency[arr[l]]++;

	while (l <= r && r < n)
	{
		if (count <= 2)
		{
			answer = max(answer, r - l + 1);
			r++;
			if (frequency[arr[r]] == 0)
				count++;
			frequency[arr[r]]++;
		}
		else
		{
			frequency[arr[l]]--;
			if (frequency[arr[l]] == 0)
				count--;
			l++;
		}
	}

	cout << answer;

	return 0;
}
