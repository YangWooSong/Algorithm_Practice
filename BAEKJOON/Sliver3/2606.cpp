#include <iostream>
#include <queue>
using namespace std;

int computer, count_pair;
int arr[101][101] = { 0 };
bool visited[101] = {};
queue<int> q;
int count_influence = 0;

void bfs(int num) {
	visited[num] = true;
	q.push(num);

	while (q.empty() == false)
	{
		num = q.front();
		q.pop();

		for (int i = 1; i <= computer; ++i)
		{
			if (arr[num][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = true;
				count_influence++;
			}
		}
	}
}
int main() {
	cin >> computer >> count_pair;

	for (int i = 0; i < count_pair; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		arr[n1][n2] = 1;
		arr[n2][n1] = 1;
	}

	bfs(1);

	cout << count_influence;

	return 0;
}