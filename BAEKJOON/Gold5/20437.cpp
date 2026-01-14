#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int totalCount = 0;
	cin >> totalCount;

	while (totalCount--)
	{
		string s;
		int k = 0;
		cin >> s >> k;

		vector<int> pos[26];

		//문자별 인덱스 저장
		for (int i = 0; i < s.size(); ++i) {
			pos[s[i] - 'a'].push_back(i);
		}

		int minLen = 10000;
		int maxLen = -1;

		//문자별로 k개 연속 묶기
		for (int i = 0; i < 26; ++i)
		{
			if (pos[i].size() < k)
				continue;

			for (int j = 0; j + k - 1 < pos[i].size(); ++j)
			{
				int newLen = pos[i][j + k - 1] - pos[i][j] + 1;
				minLen = min(minLen, newLen);
				maxLen = max(maxLen, newLen);
			}

		}

		if (maxLen == -1)
			cout << -1 << "\n";
		else
			cout << minLen << " " << maxLen << "\n";
	}
	return 0;
}