#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	Init();

	string sInput;
	cin >> sInput;

	int arr[26] = {};
	int iMaxCharCount = 0;

	//알파벳 개수 세기
	for (int i = 0; i < sInput.size(); ++i)
	{
		int index = 0;
		if (isupper(sInput[i]))
		{
			index = sInput[i] - 'A';
			
		}
		else
		{
			index = sInput[i] - 'a';
		}

		arr[index]++;
		if (arr[index] > iMaxCharCount)
			iMaxCharCount = arr[index];
	}

	int iAlphaCount = 0;
	int iMaxAlphaIndex = 0;
	//가장 많이 나온 알파벳 찾기
	for (int i = 0; i < 26; ++i)
	{
		if (arr[i] == iMaxCharCount)
		{
			iMaxAlphaIndex = i;
			iAlphaCount++;
		}
	}

	if (iAlphaCount > 1)
		cout << "?" << "\n";
	else
		cout << (char)(iMaxAlphaIndex + 'A') << "\n";

	return 0;
}