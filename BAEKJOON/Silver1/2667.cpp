#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int arr[26][26] = {};
int visited[26][26] = {};
int n = 0;
int n_count = 0;

void DFS(int x, int y, int& h_count)
{
    if (visited[x][y])
        return;

    visited[x][y] = true;
    h_count += 1;

    if (x > 0 && arr[x - 1][y] == 1)
    {
        DFS(x - 1, y, h_count);
    }
    if (x + 1 < n && arr[x + 1][y] == 1)
    {
        DFS(x + 1, y, h_count);
    }
    if (y + 1 < n && arr[x][y + 1] == 1)
    {
        DFS(x, y + 1, h_count);
    }
    if (y > 0 && arr[x][y - 1] == 1)
    {
        DFS(x, y - 1, h_count);
    }
}


int main() {

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j)
        {
            arr[i][j] = s[j] - '0';
        }
    }

    vector<int> h_countArr;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visited[i][j] == false && arr[i][j] == 1)
            {
                n_count++;
                int house_count = 0;
                DFS(i, j, house_count);
                h_countArr.push_back(house_count);
            }
        }
    }

    sort(h_countArr.begin(), h_countArr.end());

    cout << n_count << "\n";

    for (int i =0; i < h_countArr.size(); ++i )
    {
        cout << h_countArr[i] << "\n";
    }
    return 0;
}