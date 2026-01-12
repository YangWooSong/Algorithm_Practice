#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
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
	string sInput;
	getline(cin, sInput);

	string sTmp;
	string sAnswer;
	bool bNoReverse = false;
	for (int i = 0; i < sInput.size(); ++i)
	{
		if (sInput[i] == '<')
		{
			reverse(sTmp.begin(), sTmp.end());
			sAnswer += sTmp;
			sTmp = "";
;			sAnswer += '<';
			bNoReverse = true;
			continue;
		}

		else if (sInput[i] == '>')
		{
			sAnswer += sTmp;
			sAnswer += '>';
			sTmp = "";
			bNoReverse = false;
			continue;
		}

		if(bNoReverse)
			sAnswer += sInput[i];
		else
		{
			if (sInput[i] == ' ')
			{
				reverse(sTmp.begin(), sTmp.end());
				sAnswer += sTmp;
				sTmp = "";
				sAnswer += " ";
			}
			else
				sTmp += sInput[i];
		}
	}

	if (!sTmp.empty())
	{
		reverse(sTmp.begin(), sTmp.end());
		sAnswer += sTmp;
	}

	cout << sAnswer;

	return 0;
}