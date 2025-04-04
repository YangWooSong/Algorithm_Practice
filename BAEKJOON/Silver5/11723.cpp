#include <iostream>
#include <set>
using namespace std;

set<int> set_num;
int bit = 0;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void Add() {
	int tmp = 0;
	cin >> tmp;
	bit |= (1 << tmp);
}

void Remove() {
	int tmp = 0;
	cin >> tmp;
	bit &= ~(1 << tmp);
}

void Check() {
	int tmp = 0;
	cin >> tmp;
	if (bit & (1 << tmp))
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}

void Toggle() {
	int tmp = 0;
	cin >> tmp;
	bit ^= (1 << tmp);
}

void InputNum() {
	string s;
	cin >> s;

	if (s == "add") {
		Add();
	}
	else if (s == "remove") {
		Remove();
	}
	else if (s == "check") {
		Check();
	}
	else if (s == "toggle") {
		Toggle();
	}
	else if (s == "all") {
		bit = (1 << 21) - 1;
	}
	else if (s == "empty") {
		bit = 0;
	}
}

int main() {
	Init();

	int m = 0;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		InputNum();
	}
	return 0;
}