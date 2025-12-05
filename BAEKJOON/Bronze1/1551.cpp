#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void change(vector<int>& arr)
{
	vector<int> newArr;
	newArr.reserve(arr.size() - 1);

	for (int i = 0; i < arr.size()-1; ++i)
	{
		newArr.push_back(arr[i + 1] - arr[i]);
	}

	arr.swap(newArr);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	cin.ignore();

	vector<int> arr;
	string s;
	string word;
	char delimiter = ',';
	getline(cin, s);

	stringstream ss(s);
	while (getline(ss, word, delimiter))
	{
		arr.push_back(stoi(word));
	}

	for (int i = 0; i < K; ++i)
	{
		change(arr);
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		if (i != 0)
			cout << ",";
		cout << arr[i];
	}

	return 0;
}