#include <iostream>
#include <queue>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}



int main() {
	Init();
	priority_queue<int> q;
	int count = 0;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		int tmp = 0;
		cin >> tmp;

		if (tmp == 0)
		{
			if (q.size() == 0)
				cout << 0 << "\n";
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
			q.push(tmp);
	}

	return 0;
}
