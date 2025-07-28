#include <iostream>
using namespace std;

void Init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

long divide(long n1, long n2)
{
	if (n1 % n2 == 0)
		return n1 / n2;
	else
		return n1 / n2 + 1;
}

int main()
{
	Init();

	long R = 0, C = 0, N = 0;
	long r = 0, c = 0;

	cin >> R >> C >> N;

	R = divide(R, N);
	C = divide(C, N);

	cout << R * C;

	return 0;
}