#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;
	cin >> count;

	map<string, int> arr;

	for (int i = 0; i < count; ++i)
	{
		string s;
		cin >> s;

		string extension = s.substr(s.find('.') + 1);

		arr[extension]++;
	}

	for (auto &a : arr)
	{
		cout << a.first << " " << a.second << "\n";
	}

	return 0;
}