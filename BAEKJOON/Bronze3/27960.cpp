#include <iostream>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	Init();

	unsigned int num1, num2;
	cin >> num1 >> num2;

	cout << (num1 ^ num2);

	return 0;
}
