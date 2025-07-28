#include <iostream>
#include <vector>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int sumV(vector<int> fV) {
	int sum = 0;
	int smallest = 100;
	for (int i = 0; i < fV.size(); ++i)
	{
		sum += fV[i];

		if (smallest > fV[i])
		{
			smallest = fV[i];
		}
	}

	sum -= smallest;
	return sum;
}

int main() {

	vector<int> firstV;
	vector<int> secondV;
	firstV.resize(4);
	secondV.resize(2);
	int total = 0;

	for (int i = 0; i < 4; ++i)
	{
		cin >> firstV[i];
	}
	for (int i = 0; i < 2; ++i)
	{
		cin >> secondV[i];
	}

	total = sumV(firstV) + sumV(secondV);
	cout << total;

	return 0;
}
