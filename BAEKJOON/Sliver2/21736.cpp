#include <iostream>
using namespace std;

char arr[601][601] = {};
int In, Im;
int n, m;
bool isVisited[601][601] = {};
int P_count = 0;

void Init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void find(int _n, int _m)
{
    if (isVisited[_n][_m] || arr[_n][_m] == 'X')
        return;

    isVisited[_n][_m] = true;
    if (arr[_n][_m] == 'P')
        P_count++;

    if (_n > 0)
    {
        find(_n - 1, _m);
    }
    if (_n < n - 1)
    {
        find(_n + 1, _m);
    }
    if (_m > 0)
    {
        find(_n, _m - 1);
    }
    if (_m < m - 1)
    {
        find(_n, _m + 1);
    }
}

int main()
{
    Init();

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'I')
            {
                In = i;
                Im = j;
            }
        }
    }

    find(In, Im);

    if (P_count == 0)
        cout << "TT";
    else
        cout << P_count;

    return 0;
}