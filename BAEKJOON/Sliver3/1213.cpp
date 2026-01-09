#include <iostream>
#include <string>
#include <algorithm>
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

	int alphaCountArr[26] = {};
	
	//알파벳 개수 세기
	for (char a : sInput)
	{
		alphaCountArr[a - 'A']++;
	}

	//홀수 개수 세기
	int oddCount = 0;
	char oddChar = 0;	//중앙에 들어갈 알파벳
	for (int i = 0; i < 26; ++i)
	{
		if (alphaCountArr[i] % 2 != 0)
		{
			oddCount++;
			oddChar = i + 'A';
		}
	}

	//홀수가 한 개 이상이면 펠린드롬 불가능
	if (oddCount > 1)
	{
		cout << "I'm Sorry Hansoo\n";
		return 0;
	}

	string front = "";
	{
		for (int i = 0; i < 26; ++i)
		{
			front.append(alphaCountArr[i] / 2, char(i + 'A'));
		}
	}

	string back = front;
	reverse(back.begin(), back.end());

	if (oddCount != 0)
		cout << front + oddChar + back << "\n";
	else
		cout << front + back << "\n";

	return 0;
}