#include <iostream>
#include <queue>
using namespace std;

int arr[101] = {};
int visited[101] = {-1};
int ladder, snake;

void BFS()
{
	queue<int> q;
	
	q.push(1);
	fill(visited, visited + 101, -1);	//-1로 초기화
	visited[1] = 0;						//처음 시작 (주사위 굴린적 없음)

	while (!q.empty())
	{
		int curIndex = q.front();
		q.pop();

		for (int i = 1; i <= 6; ++i)
		{
			int newIndex = curIndex + i;
			if (newIndex > 100) continue;

			if (arr[newIndex] != 0)			//사라디, 뱀 적용
				newIndex = arr[newIndex];

			if (visited[newIndex] == 0)
			{
				visited[newIndex] = visited[curIndex] + 1;
				q.push(newIndex);
			}
		
		}
	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> ladder >> snake;

	for (int i = 0; i < ladder + snake; ++i)
	{
		int start, target;
		cin >> start >> target;

		arr[start]= target;
	}

	BFS();

	cout << visited[100];

	return 0;
}