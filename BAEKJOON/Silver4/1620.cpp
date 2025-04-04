#include <iostream>	
#include <map>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> key_string;
	map<int, string> key_int;

	for (int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		key_string.insert({ name, i+1 });
		key_int.insert({ i+1, name, });
	}

	for (int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;

		if (isdigit(s[0])) // 숫자 입력
		{
			cout << key_int[stoi(s)] << "\n";
		}
		else
			cout << key_string.find(s)->second << "\n";

	}

	return 0;
}