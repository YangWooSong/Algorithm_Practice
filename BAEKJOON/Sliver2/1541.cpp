#include <iostream>
#include <string>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main() {
	Init();
	string s;
	cin >> s;

	bool isMinus = false;
	string num;
	int sum = 0;
	for (int i = 0; i <= s.size(); ++i)
	{
		if (s[i] == '+' || s[i] == '\0' || s[i] == '-')
		{
			if (isMinus)
				sum -= stoi(num);
			else
				sum += stoi(num);
			num = "";
			if (s[i] == '-')
				isMinus = true;
		}
		else
			num += s[i];
	}

	cout << sum;
	return 0;
}
