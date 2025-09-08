#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> v[102];
int a, b;
int peopleCount = 0; // 시작 사람에서 목표 사람 까지의 단계 수

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
        v[a].push_back(b); // 사람 관계는 양방향임.
        v[b].push_back(a);
    }

    int result = 5000;
    int num; // 케빈 베이컨의 수에 해당하는 사람 번호
    for (int i = 1; i <= n;i++) { // 시작하는 사람
        int tmep_Count = 0; 
        for (int j = 1; j <= n;j++) { // 목표사람
            bool visit[102] = { 0 };
            if (i == j) 
                continue;
            bfs(i, j, visit);
            tmep_Count += peopleCount; // 각 목표 사람의 단계를 모두 합쳐 케빈 베이컨의 수를 구함
            peopleCount = 0; // 목표 사람의 단계 초기화
        }
        if (result > tmep_Count) { // 전의 케빈 베이컨의 수와 비교하여 더 작은 값을 저장
            result = tmep_Count;
            num = i;
        }

    }
    cout << num << '\n';
    return 0;
}