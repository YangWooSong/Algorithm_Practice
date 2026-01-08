#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

void Init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second != b.second)
		return a.second > b.second;

	if (a.first.length() != b.first.length())
		return a.first.length() > b.first.length();

	return a.first < b.first;

}

int main()
{
	Init();

	int n, m;
	cin >> n >> m;

	unordered_map<string, int> wordCount;
	vector < pair<string, int>> stringVector;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		if (s.length() >= m)
		{
			if (wordCount.find(s) == wordCount.end())
				wordCount.insert({ s,1 });
			else
				wordCount[s]++;
		}
	}

	for (auto& iter : wordCount)
	{
		stringVector.push_back(make_pair(iter.first, iter.second));
	}
	
	sort(stringVector.begin(), stringVector.end(), cmp);

	for (auto& iter : stringVector)
	{
		cout << iter.first << "\n";
	}

	return 0;
}