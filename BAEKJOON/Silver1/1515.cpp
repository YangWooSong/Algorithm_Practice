#include <iostream>
#include <string>
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
	cin >> sInput;

	int iCmpNum = 0;
	int iStrIndex = 0;
	while (sInput.size() - 1 >= iStrIndex)
	{
		iCmpNum++;
		string sCmpString = to_string(iCmpNum);

		for (int i = 0; i < sCmpString.size(); ++i)
		{
			if (sCmpString[i] == sInput[iStrIndex])
			{
				iStrIndex++;
			}
		}
	}

	cout << iCmpNum;

	return 0;
}