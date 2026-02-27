#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    //0~9가 한번씩만 나올 수 있음, 즉 최대 개수 : 2^10 - 1 (부분 집합 - 공집합)
    if (n > 1023)
    {
        cout << -1;
        return 0;
    }

    queue<long long> q;
    vector<long long> v;

    for (int i = 0; i < 10; ++i)
    {
        q.push(i);
        v.push_back(i);
    }

    while (!q.empty())
    {
        long long curNum = q.front();
        q.pop();
        int lastNum = curNum % 10;

        for (int i = 0; i < 10; ++i)
        {
            if (i < lastNum)
            {
                long long newNum = curNum * 10 + i;
                q.push(newNum);
                v.push_back(newNum);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v[n - 1];

    return 0;
}