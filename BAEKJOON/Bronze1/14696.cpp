#include <iostream>
#include <vector>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	Init();
	
	int round = 0;
	cin >> round;

	for (int i = 0; i < round; ++i)
	{
		int A_Count, B_Count;
		cin >> A_Count;

		vector<int> A_input;
		A_input.resize(4);
		for (int j = 0; j < A_Count; ++j)
		{
			int tmp;
			cin >> tmp;

			A_input[tmp-1]++;
		}

		cin >> B_Count;

		vector<int> B_input;
		B_input.resize(4);
		for (int j = 0; j < B_Count; ++j)
		{
			int tmp;
			cin >> tmp;

			B_input[tmp-1]++;
		}

		char answer;

		for (int j = 3; j >= 0; --j)
		{
			if (A_input[j] > B_input[j])
			{
				answer = 'A';
				break;
			}
			else if (A_input[j] < B_input[j])
			{
				answer = 'B';
				break;
			}
			else
				answer = 'D';
		}

		cout << answer << "\n";
	}
	return 0;
}
