#include <iostream>
#include <queue>
using namespace std;

void Init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int Find_Biggest(queue<int> _documents)
{
	int tmp = 0;

	for (int i = 0 ;_documents.empty() == false; ++i)
	{
		if (_documents.front() > tmp)
			tmp = _documents.front();

		_documents.pop();
	}

	return tmp;
}

int main()
{
	int testCase = 0; //test case

	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int N = 0; //Document Count
		int M = 0; //Main Document place
		int answer = 0;
		int count = 0; //print count
		queue<int> documents;


		cin >> N >> M;

		for (int num, i = 0; i < N; ++i)
		{
			cin >> num;
			documents.push(num);
		}

		int Biggest = Find_Biggest(documents);

		for (; documents.empty() == false > 0;)
		{
			//�� �� ���� ���� ū�� Ȯ��
			if (documents.front() != Biggest) //���� ū ���� �ƴ� ��
			{
				documents.push(documents.front());
				documents.pop();
				if (M> 0)
					M--;	//�ٸ� ������ �ڷ� �̵�
				else
					M = documents.size()-1;  //���� ������ �ڷ� �̵�
			}
			else // ���� ū ���̶� ��� �� ��
			{
				count++;
				documents.pop();
				
				if (M == 0)
				{
					answer = count;
					break;
				}
				else
					--M;

				Biggest = Find_Biggest(documents);

			}

		}

		cout << answer << "\n";
	}
	

	return 0;
}