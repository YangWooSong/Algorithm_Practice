#include <iostream>
#include <string>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int Arr[128][128] = {};
int countWhite = 0;
int countBlue = 0;

void Count(int iN, int jN, int N)
{
	bool isWhite = true;	
	bool isBlue = true;

	for (int i = iN; i < iN + N; ++i)
	{
		for (int j = jN; j < jN + N; ++j)
		{
			if (Arr[i][j] == 0 && isBlue == true)
				isBlue = false;
			else if (Arr[i][j] == 1 && isWhite == true)
				isWhite = false;

			if (isBlue == false && isWhite == false)
				break;
		}

		if (isBlue == false && isWhite == false)
			break;
	}

	if (isBlue)
		countBlue++;
	else if (isWhite)
		countWhite++;
	else
	{
		Count(iN, jN, N / 2);
		Count(iN, jN + N/2, N / 2);
		Count(iN + N / 2, jN, N / 2);
		Count(iN + N / 2, jN + N/2, N / 2);
	}
}	

int main() {
	Init();

	int N;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Arr[i][j];
		}
	}

	Count( 0, 0, N);

	cout << countWhite << "\n" << countBlue;

	return 0;
}
