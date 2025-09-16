#include <iostream>
#include <string>
using namespace std;


int main() {
    int n, m;
    string s, p;

    cin >> n;
    cin >> m;
    cin >> s;


    int count = 0;

    for (int i = 0; i < m; ++i)
    {
        if (s[i] == 'O')
            continue;

        int tmp = 0;

        while (s[i + 1] == 'O' && s[i + 2] == 'I')
        {
            tmp++;
            
            if (tmp == n)
            {
                tmp--;
                count++;
            }

            i += 2;
        }
    }

    cout << count;
   

    return 0;
}