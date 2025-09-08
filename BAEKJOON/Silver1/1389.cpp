#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> v[102];
int a, b;
int peopleCount = 0; // ���� ������� ��ǥ ��� ������ �ܰ� ��

void bfs(int a, int b, bool visit[102]) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    visit[a] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (x == b) {
            peopleCount = cnt;
            break;
        }

        for (int i = 0; i < v[x].size(); i++) {
            if (!visit[v[x][i]]) {
                q.push(make_pair(v[x][i], cnt + 1));
                visit[v[x][i]] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m;i++) {
        cin >> a >> b;
        v[a].push_back(b); // ��� ����� �������.
        v[b].push_back(a);
    }

    int result = 5000;
    int num; // �ɺ� �������� ���� �ش��ϴ� ��� ��ȣ
    for (int i = 1; i <= n;i++) { // �����ϴ� ���
        int tmep_Count = 0; 
        for (int j = 1; j <= n;j++) { // ��ǥ���
            bool visit[102] = { 0 };
            if (i == j) 
                continue;
            bfs(i, j, visit);
            tmep_Count += peopleCount; // �� ��ǥ ����� �ܰ踦 ��� ���� �ɺ� �������� ���� ����
            peopleCount = 0; // ��ǥ ����� �ܰ� �ʱ�ȭ
        }
        if (result > tmep_Count) { // ���� �ɺ� �������� ���� ���Ͽ� �� ���� ���� ����
            result = tmep_Count;
            num = i;
        }

    }
    cout << num << '\n';
    return 0;
}