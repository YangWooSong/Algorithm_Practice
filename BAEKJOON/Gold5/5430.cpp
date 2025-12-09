#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		string p;
		string s_arr;
		cin >> p;

		int n = 0;
		cin >> n;

		deque<int> q;
		cin >> s_arr;

		//숫자가 1의 자리수가 아닐 수도


		string s_num = "";
		for (char c : s_arr)
		{
			if (isdigit(c))
				s_num += c;
			else
			{
				if (!s_num.empty())
				{
					q.push_back(stoi(s_num));
					s_num = "";
				}
			}
		}

		bool bReverse = false;
		bool bError = false;

		for (char c : p)
		{
			if (c == 'R')
			{
				bReverse = !bReverse;
			}
			else if (c == 'D')
			{
				if (q.empty())
				{
					bError = true;
					break;
				}

				if (bReverse)
					q.pop_back();
				else
					q.pop_front();
			}
		}

		if (bError)
			cout << "error \n";
		else
		{
			cout << "[";

			if (bReverse)
			{
				for (int j = q.size() - 1; j >= 0; --j)
				{
					cout << q[j];
					if (j > 0 )
						cout << ",";
				}
			}
			else
			{
				for (int j = 0; j < q.size(); ++j)
				{
					cout << q[j];
					if (j + 1 < q.size())
						cout << ",";
				}
			}
			cout << "]\n";
		}

	}
	return 0;
}