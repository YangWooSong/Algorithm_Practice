#include <iostream>	
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<string> name;
	set<string> both;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		name.insert(s);
	}

	for (int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;
		if (name.find(s) != name.end())
			both.insert(s);
	}

	//sort(both.begin(), both.end());

	cout << both.size() << "\n";
	for (auto& iter : both)
	{
		cout << iter << "\n";
	}
	return 0;
}
