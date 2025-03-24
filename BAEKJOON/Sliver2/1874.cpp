#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void Init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	Init();

	int n = 0;
	cin >> n;

	stack<int> stack_fin;
	vector<int> input_vector;
	vector<char> input_answer;

	for (int a, i = 0; i < n; ++i)
	{
		cin >> a;
		input_vector.push_back(a);
	}

	int num = 1;
	int index = 0;
	bool no = false;

	while (1)
	{
		if (stack_fin.size() == 0 && num == n+1)
			break;

		if (stack_fin.empty() == false)
		{
			if (stack_fin.top() == input_vector[index])
			{
				input_answer.push_back('-');
				index++;
				stack_fin.pop();
			}
			else if (stack_fin.top() > input_vector[index])
			{
				no = true;
				break;
			}
			else
			{
				input_answer.push_back('+');
				stack_fin.push(num);
				num++;
			}
		}
		else
		{
			input_answer.push_back('+');
			stack_fin.push(num);
			num++;
		}
	}

	if (no)
		cout << "NO";
	else
	{
		for (auto& iter : input_answer)
		{
			cout << iter << "\n";
		}
	}
	return 0;
}