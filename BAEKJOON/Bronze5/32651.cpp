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
	int N = 0;
	cin >> N;

	cout << N - 2024;

	return 0;
}