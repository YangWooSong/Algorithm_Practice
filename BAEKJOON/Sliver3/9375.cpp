#include <iostream>
#include <map>
using namespace std;

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	Init();
	
	int TC = 0;
	cin >> TC;


	for (int i = 0; i < TC; ++i)
	{
		map<string, int> clothes;

		int clothes_count = 0;
		cin >> clothes_count;

		string name, type;
		for (int j = 0; j < clothes_count; ++j)
		{
			cin >> name >> type;

			if (clothes.find(type) == clothes.end())
				clothes.insert({ type, 1 });
			else
			{
				auto iter = clothes.find(type);
				iter->second++;
			}
		}

		int sum = 1;
		for (auto iter : clothes)
		{
			sum *= iter.second+1;
		}

		cout << sum - 1 << "\n";
	}
	return 0;
}
