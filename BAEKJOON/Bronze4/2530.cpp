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

	int A, B, C , D;

	cin >> A >> B >> C;
	cin >> D;

	C += D % 60;
	B += D / 60;

	if (C > 59)
	{
		B += C / 60;
		C %= 60;
	}

	if (B > 59)
	{
		A += B / 60;
		B %= 60;
	}

	if (A > 23)
	{
		A %= 24;
	}

	cout << A << " " << B << " " << C;

	return 0;
}