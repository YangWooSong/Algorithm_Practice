#include <iostream>
#include <vector>
#include <string>
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

void countAlpha(string tmp, vector<int>& list)
{
	for (int i = 0; i < tmp.size(); ++i)
	{
		if(tmp[i] != ' ')
			list[tmp[i] - 'a']++;
	}
}

void findMostAlpha(vector<int>& list)
{
	int index = 0, max = 0;
	bool noMax = false;
	for (int i = 0; i < list.size(); ++i)
	{
		if (list[i] > max)
		{
			noMax = false;
			max = list[i];
			index = i;
		}
		else if (list[i] == max)
		{
			noMax = true;
		}
	}

	if (noMax)
		cout << "?" << "\n";
	else
	{
		cout << (char)('a' + index) << "\n";
	}
}

int main()
{
	Init();

	int count = 0;
	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; ++i)
	{
		string tmp;
		getline(cin, tmp);

		vector<int> alphaList;
		alphaList.resize(26);

		countAlpha(tmp, alphaList);
		findMostAlpha(alphaList);
	}

	return 0;
}