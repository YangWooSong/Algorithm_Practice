#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
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

	int n, m;
	cin >> n >> m;

	set<string> notHear;
	vector<string> notBoth;

	for (int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		notHear.insert(name);
	}

	for (int i = 0; i < m; ++i)
	{
		string name;
		cin >> name;
		if (notHear.count(name) > 0)
			notBoth.push_back(name);
	}

	sort(notBoth.begin(), notBoth.end());

	cout << notBoth.size() << "\n";

	for (int i = 0; i < notBoth.size(); ++i)
	{
		cout << notBoth[i] << "\n";
	}

	return 0;
}