#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

struct node
{
	bool isSelected = false;
	vector<int> linked;
};

void DFS(vector<node>& nl, int index)
{
	if (nl[index].isSelected == true)
		return;

	nl[index].isSelected = true;
	cout << index << " ";

	for (int i = 0; i < nl[index].linked.size(); ++i)
	{
		DFS(nl, nl[index].linked[i]);
	}

}

void BFS(vector<node> &nl, int index)
{
	queue < int> q;

	q.push(index);
	nl[index].isSelected = true;

	while (q.empty() != true)
	{
		int curIndex = q.front();
		q.pop();

		for (int i = 0; i < nl[curIndex].linked.size(); ++i)
		{
			if(nl[nl[curIndex].linked[i]].isSelected == false)
			{
				nl[nl[curIndex].linked[i]].isSelected = true;
				q.push(nl[curIndex].linked[i]);
			}
		}
	
		cout << curIndex << " ";
	}
}

int main() {
	Init();
	
	int N, M, V;

	cin >> N >> M >> V;

	vector<node> list;
	vector<node> DFS_list;
	vector<node> BFS_list;
	list.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;

		list[n1].linked.push_back(n2);
		list[n2].linked.push_back(n1);
	}

	for (int i = 1; i <= N; ++i) {
		sort(list[i].linked.begin(), list[i].linked.end());
	}
	DFS_list = list;
	BFS_list = list;
	DFS(DFS_list, V);
	cout << "\n";
	BFS(BFS_list, V);

	return 0;
}
