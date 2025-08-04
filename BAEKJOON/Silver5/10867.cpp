#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	Init();
	
	int count = 0;
	cin >> count;

	vector<int> numList;
	numList.resize(count);

	for (int i = 0; i < count; ++i)
	{
		cin >> numList[i];
	}

	vector<int> answer;
	sort(numList.begin(), numList.end());
	numList.erase(unique(numList.begin(), numList.end()), numList.end());

	for (int i = 0; i < numList.size(); ++i)
	{
		cout << numList[i] << " ";
	}

	return 0;
}
