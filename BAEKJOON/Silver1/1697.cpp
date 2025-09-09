#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool visited[100001];

void BFS(int x)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x, 0));
    visited[x] = true;

    while (!q.empty())
    {
        int num = q.front().first;
        int time = q.front().second;
        q.pop();

        if (num == k)
        {
            cout << time;
            break;
        }

        if (num + 1 <= 100000 && visited[num + 1] == false)
        {
            visited[num + 1] = true;
            q.push(make_pair(num + 1, time + 1));
        }

        if (num - 1 >= 0 && visited[num - 1] == false)
        {
            visited[num - 1] = true;
            q.push(make_pair(num - 1, time + 1));
        }

        if (num * 2 <= 100000 && visited[num * 2] == false)
        {
            visited[num * 2] = true;
            q.push(make_pair(num * 2, time + 1));
        }
    }

}

int main() {
    
    cin >> n >> k;

    BFS(n);

    return 0;
}