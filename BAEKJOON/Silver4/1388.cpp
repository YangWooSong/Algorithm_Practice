#include <iostream>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	Init();

	int n, m;
	cin >> n >> m;

	char list[50][50] = {};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> list[i][j];
		}
	}

	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (list[i][j] == '-')
			{
				if(j > 0 && j < m)
				{
					if (list[i][j - 1] == '-')
						continue;
					else
						count++;
				}
				else
				{
					count++;
				}
			}
			else if (list[i][j] == '|')
			{
				if (i > 0 && i < n)
				{
					if (list[i - 1][j] == '|')
						continue;
					else
						count++;
				}
				else
				{
					count++;
				}
			}
		}
	}

	cout << count;
	return 0;
}