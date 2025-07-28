#include <iostream>
using namespace std;

void Init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int find(string s)
{
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == '0' && s[i + 1] == '1')
			return 1;
		else if (s[i] == 'O' && s[i+1] == 'I')
			return 1;
	}

	return 0;
}

int main()
{
	Init();

	int count = 0;
	cin >> count;

	int total = 0;

	for (int i = 0; i < count; ++i)
	{
		string tmp;
		cin >> tmp;

		total += find(tmp);
	}

	cout << total;

	return 0;
}