#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc)
	{
		int t = 0;
		cin >> t;

		char c;
		int num = 0;
		int id = 0;
		priority_queue<pair<int,int>> maxQ;
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>> minQ;
		vector<bool> visited(t, false);	//최대 t번 삽입이 가능하니까

		for (int i = 0; i < t; ++i)
		{
			cin >> c >> num;

			if (c == 'I')
			{
				maxQ.push({ num, id });
				minQ.push({ num, id });
				visited[id] = true;	//살아있다
				id++;
			}
			else if (c == 'D' )
			{
				if (num == 1)
				{
					//minQ랑 동기화
					while (!maxQ.empty() && visited[maxQ.top().second] == 0)
					{
						maxQ.pop();
					}

					if (!maxQ.empty())
					{
						visited[maxQ.top().second] = false;
						maxQ.pop();
					}
				}
				else
				{
					//manQ랑 동기화
					while (!minQ.empty() && visited[minQ.top().second] == 0)
					{
						minQ.pop();
					}

					if (!minQ.empty())
					{
						visited[minQ.top().second] = false;
						minQ.pop();
					}
				}
			}	
		}
		
		//최종 동기화
		while (!maxQ.empty() && visited[maxQ.top().second] == 0)
		{
			maxQ.pop();
		}

		while (!minQ.empty() && visited[minQ.top().second] == 0)
		{
			minQ.pop();
		}

		if (minQ.empty() || maxQ.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << maxQ.top().first << " " << minQ.top().first << "\n";
		}

		tc--;
	}
	return 0;
}