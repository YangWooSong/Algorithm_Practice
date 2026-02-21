#include <iostream>
using namespace std;

char arr[101][101] = {};
int normalVisited[101][101] = {};
int blindVisited[101][101] = {};
int normalA = 0;
int colorBlindA = 0;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int n = 0;

void normalDFS(int i, int j)
{
	normalVisited[i][j] = 1;
	char c = arr[i][j];

	for (int k = 0; k < 4; ++k)
	{
		int newY = i + dir[k][0];
		int newX = j + dir[k][1];

		if (newX >= 0 && newX < n && newY >= 0 && newY < n)
		{
			if (normalVisited[newY][newX] == 0 && c == arr[newY][newX])
			{
				normalDFS(newY, newX);
			}//
		}
	}
}

void blindDFS(int i, int j)
{
	blindVisited[i][j] = 1;
	char c = arr[i][j];

	for (int k = 0; k < 4; ++k)
	{
		int newY = i + dir[k][0];
		int newX = j + dir[k][1];

		if (newX >= 0 && newX < n && newY >= 0 && newY < n)
		{
			if (blindVisited[newY][newX] == 0 )
			{
				if (c == 'B')
				{
					if(arr[newY][newX] == 'B')
						blindDFS(newY, newX);
				}
				else
				{
					if (arr[newY][newX] == 'R' || arr[newY][newX] == 'G')
						blindDFS(newY, newX);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(normalVisited[i][j] == 0)
			{
				normalA++;
				normalDFS(i, j);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (blindVisited[i][j] == 0)
			{
				colorBlindA++;
				blindDFS(i, j);
			}
		}
	}

	cout << normalA << " " << colorBlindA;

	return 0;
}