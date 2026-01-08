#include <iostream>
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

	/*모음(a, e, i, o, u) 하나를 반드시 포함하여야 한다.
		모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
		같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.*/
	char mo[5] = { 'a', 'e', 'i', 'o', 'u' };
	
	while (true)
	{
		string sInput;
		cin >> sInput;

		if (sInput == "end")
			break;

		bool bHaveMo = false;
		bool bDouble = false;
		bool bTripple = false;
		int iMoCount = 0;
		int iZaCount = 0;
		char cPastChar = {};

		for (int i = 0; i < sInput.length(); ++i)
		{
			bool bIsThisAlphaMo = false;
			//모음 있는지 확인
			for (int j = 0; j < 5; ++j)
			{
				if (sInput[i] == mo[j])
				{
					bIsThisAlphaMo = true;
					bHaveMo = true;
				}
			}
			
			if (bIsThisAlphaMo)
			{
				iZaCount = 0;
				iMoCount++;
			}
			else
			{
				iMoCount = 0;
				iZaCount++;
			}

			if (iZaCount >= 3 || iMoCount >= 3)
				bTripple = true;

			if (i == 0)
			{
				cPastChar = sInput[i];
				continue;
			}

			//2개 연속 금지, e,o 제외
			if (sInput[i] == cPastChar)
			{
				bDouble = true;
				if (cPastChar == 'e' || cPastChar == 'o')
					bDouble = false;
			}

			cPastChar = sInput[i];
		}

		if (bHaveMo == false || bTripple || bDouble)
		{
			cout << "<" << sInput << "> is not acceptable.\n" ;
		}
		else
		{
			cout << "<" << sInput << "> is acceptable.\n";
		}

	}

	return 0;
}