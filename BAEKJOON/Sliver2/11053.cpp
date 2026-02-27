#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    vector<int> v(n);
    vector<int> tmp;

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int curNum = v[i];
        if (tmp.empty() || tmp[tmp.size() - 1] < curNum)
        {
            tmp.push_back(curNum);
        }
        else
        {
            int index = lower_bound(tmp.begin(), tmp.end(), curNum) - tmp.begin();
            tmp[index] = curNum;
        }

    }

    cout << tmp.size();

    return 0;
}