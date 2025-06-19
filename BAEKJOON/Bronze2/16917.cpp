#include <iostream>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int yangePrice, PhuPrice, banPrice, X, Y;

bool buyBan()
{
	int sum = yangePrice + PhuPrice;

	if (sum > banPrice * 2)
		return true;
	else
		return false;
}

int main() {
	Init();
	
	cin >> yangePrice >> PhuPrice >> banPrice >> X >> Y;

	bool buyHalf = buyBan();

	int sum = 0;

	if (buyHalf)
	{
		int minCount = min(X, Y);
		int	maxCount = max(X, Y);
		int chickPrice = 0;

		if (maxCount == X)
			chickPrice = yangePrice;
		else
			chickPrice = PhuPrice;

		sum = min(maxCount * 2 * banPrice, banPrice * (minCount * 2) + (maxCount - minCount) * chickPrice);

	}
	else
	{
		sum = X * yangePrice + Y * PhuPrice;
	}

	cout << sum;
	return 0;
}
