#include <iostream>
#include <bitset>
#include <string>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	Init();

	string s_input;
	string mainStation;
	string subStation;
	getline(std::cin, s_input);

	int mainNameEndIndex = 0;
	bool haveSub = false;
	for (int i = 0; i < s_input.length(); ++i)
	{
		if (s_input[i] == '(')
		{
			haveSub = true;
			mainNameEndIndex = i - 2;
		}
	}

	if (haveSub)
	{
		for (int i = 0; i < s_input.length() - 1; ++i)
		{
			if (i <= mainNameEndIndex)
			{
				mainStation += s_input[i];
			}
			else if(i >= mainNameEndIndex + 3 )
			{
				subStation += s_input[i];
			}
		}
	}
	else
	{
		mainStation = s_input;
		subStation = "-";
	}

	cout << mainStation << "\n" << subStation;

	return 0;
}
