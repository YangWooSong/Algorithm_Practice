#include <iostream>
#include<algorithm>
#include <vector>
#include <cmath>
using namespace std;

void Init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	Init();

	int n = 0;
	cin >> n;
	
	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	vector<int> score;

	for (int num, i = 0; i < n; ++i)
	{
		cin >> num;
		score.push_back(num);
	}

	sort(score.begin(), score.end());
	
	int exceptCount = round(n * 0.15f);
	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		if (i > exceptCount - 1 && i <= n - 1 - exceptCount)
			sum += score[i];
	}

	sum = (int)round((double)sum / (double)(n - exceptCount - exceptCount));

	cout << sum;

	return 0;
}