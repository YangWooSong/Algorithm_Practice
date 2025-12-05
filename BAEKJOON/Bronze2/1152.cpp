#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);

	stringstream ss(s);
	string word;
	int count = 0;
	while (ss >> word)
	{
		count++;
	}

	cout << count;


	return 0;
}