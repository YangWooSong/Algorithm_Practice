#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int s_cash = 0;
	int s_stock = 0;
	int j_cash = 0;
	int j_stock = 0;
	cin >> s_cash;
	j_cash = s_cash;

	int arr[14] = {};
	for (int i = 0; i < 14; ++i)
	{
		cin >> arr[i];
	}

	int goUp = 0;
	int goDown = 0;

	for (int i = 0; i < 14; ++i)
	{
		int today_price = arr[i];

		//ÁØÇö
		if (today_price <= j_cash)
		{
			j_stock += j_cash / today_price;
			j_cash = j_cash % today_price;
		}

		//¼º¹Î
		if (i > 0 && today_price > arr[i - 1])
		{
			goDown = 0;
			goUp++;
		}
		else if (i > 0 && today_price < arr[i - 1])
		{
			goUp = 0;
			goDown++;
		}
		else
		{
			goUp = 0;
			goDown = 0;
		}

		if (goUp >= 3)
		{
			s_cash += s_stock * today_price;
			s_stock = 0;
		}
		else if (goDown >= 3)
		{
			s_stock += s_cash / today_price;
			s_cash = s_cash % today_price;
		}
	}

	int s_total = s_cash + arr[13] * s_stock;
	int j_total = j_cash + arr[13] * j_stock;

	if (s_total == j_total)
		cout << "SAMESAME";
	else if (s_total > j_total)
		cout << "TIMING";
	else if (s_total < j_total)
		cout << "BNP";

	return 0;
}