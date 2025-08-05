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
	
	int tc = 0;
	cin >> tc;

	vector<long> arr = { 1,1,1,2,2,3 };

	for (int i = 0; i < tc; ++i)
	{
		int index = 0;
		cin >> index;

		if (index > arr.size())
		{
			for (int j = arr.size() - 1; j < index; ++j)
			{
				arr.push_back(arr[j - 4] + arr[j]);
			}
		}
		cout << arr[index-1] << "\n";
	}


	return 0;
}
