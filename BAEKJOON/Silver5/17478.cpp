#include <iostream>
using namespace std;

void Init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void printBar(int Count)
{
	for (int i = 0; i < Count - 1; ++i)
		cout << "____";
}
void printText(int Count, int Max)
{
	printBar(Count);
	cout << "\"����Լ��� ������?\"" << "\n";

	if (Count > Max)
	{
		printBar(Count);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else
	{

		for (int i = 0; i < Count - 1; ++i)
			cout << "____";
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���. \n";

		for (int i = 0; i < Count - 1; ++i)
			cout << "____";
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";

		for (int i = 0; i < Count - 1; ++i)
			cout << "____";
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

		printText(Count+1, Max);
	}

	printBar(Count);
	cout << "��� �亯�Ͽ���.\n";
}

int main()
{
	Init();

	int Max = 0;
	int Count = 1;
	cin >> Max;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	printText(Count, Max);

	return 0;
}