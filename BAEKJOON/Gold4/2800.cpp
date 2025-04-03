#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

string str;
vector<int> isSelected; // ��ü ���ڿ����� ���� �ε���, set_index���� ���� �ε���
vector<int> isVisited(10, false); // set_index���� ���� �ε���
vector<pair<int, int>> set_index; // () ��ȣ ���� �ε��� ����
set<string> answer;

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input() { //��ȣ �� �ε��� ����
    cin >> str;
    isSelected.assign(str.length(), false);

    stack<int> tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            tmp.push(i);
        }
        else if (str[i] == ')') {
            int idx = tmp.top();
            tmp.pop();
            set_index.push_back(make_pair(idx, i));
        }
    }
}

void DFS(int idx, int cnt) {
    if (cnt >= 1) { // ����(����)�� ��ȣ�� ���� 1�� �̻��̶��
        string s = "";
        for (int i = 0; i < str.length(); i++) {
            if (isSelected[i])   
                continue;
            s += str[i];
        }
        if (answer.count(s) == 0) {
            answer.insert(s);
        }
    }

    for (int i = idx; i < set_index.size(); i++) {
        if (isVisited[i])    
            continue;
        isVisited[i] = true;
        isSelected[set_index[i].first] = true;
        isSelected[set_index[i].second] = true;

        DFS(i + 1, cnt + 1);

        isVisited[i] = false;
        isSelected[set_index[i].first] = false;
        isSelected[set_index[i].second] = false;
    }
}

int main() {
    Init();

    Input();
    DFS(0, 0);

    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << '\n';
    }

    return 0;
}