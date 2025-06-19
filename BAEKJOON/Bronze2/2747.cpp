#include <iostream>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

//int Pibo(int index)
//{
//	if (index == 0)
//		return 0;
//	else if (index == 1)
//		return 1;
//
//	int sum = Pibo(index - 2) + Pibo(index - 1);
//	return sum;
//}

int main() {
	Init();

	int n = 0;
	cin >> n;
	
	int answer = 0;
	int n1, n2;

	for (int i = 0; i <= n; ++i)
	{
		if (i == 0)
		{
			answer = 0;
			n1 = 0;
		}
		else if (i == 1)
		{
			answer = 1;
			n2 = 1;
		}
		else
		{
			answer = n1 + n2;
			n1 = n2;
			n2 = answer;
		}
	}
	cout << answer;
	return 0;
}
