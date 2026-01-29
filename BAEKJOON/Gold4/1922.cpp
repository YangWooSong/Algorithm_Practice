#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 0; //컴퓨터 수
int m = 0; //연결 가능한 수
vector<pair<int, int>> adj[100001]; //(가중치, 연결된 정점) -> 인접 리스트
bool visited[100001] = {};

int prime(int start)
{
	//(가중치, 정점)을 내부구조를 벡터로 내림차순 정렬
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;  //최소 힙
	pq.push({ 0, start }); //시작 정점 넣기
	int result = 0;

	while (pq.empty() == false)
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (visited[node])
			continue;

		visited[node] = true;
		result += cost;

		for (auto& p : adj[node])
		{
			pq.push({ p.first, p.second });
		}
	}

	return result;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		adj[a].push_back(make_pair(cost, b));
		adj[b].push_back(make_pair(cost, a));
	}

	cout << prime(1);

	return 0;
}