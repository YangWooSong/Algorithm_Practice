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

	int time = 0;

	for (int i = 0; i < 4; ++i)
	{
		int tmp;
		cin >> tmp;
		time += tmp;
	}

	int m = 0, s = 0;
	
	s = time % 60;
	m = time / 60;

	cout << m << "\n" << s;

	return 0;
}