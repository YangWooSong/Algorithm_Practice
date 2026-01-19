#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string sInput, sBumb;
	cin >> sInput >> sBumb;

	stack<char> s;
	int bumbLen = sBumb.length();

	for (int i = 0; i < sInput.length(); ++i)
	{
		s.push(sInput[i]);

		if (s.top() == sBumb[bumbLen - 1] && s.size() >= bumbLen)
		{
			string tmp;

			for (int j = 0; j < bumbLen; ++j)
			{
				tmp.push_back(s.top());
				s.pop();
			}

			reverse(tmp.begin(), tmp.end());

			if (tmp != sBumb)
			{
				for (int j = 0; j < bumbLen; ++j)
				{
					s.push(tmp[j]);
				}
			}
		}
	}
	
	string answer;
	while (s.empty() == false)
	{
		answer += s.top();
		s.pop();
	}

	reverse(answer.begin(), answer.end());

	if (answer.length() == 0)
		cout << "FRULA";
	else
	{
		cout << answer;
	}
	return 0;
}