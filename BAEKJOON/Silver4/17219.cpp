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

	int n, m;
	cin >> n >> m;

	map<string, string> site_key;
	for (int i = 0; i < n; ++i) {
		string site;
		string pw;
		cin >> site >> pw;
		site_key.insert({ site, pw });
	}

	for (int i = 0; i < m; ++i){
		string site;
		cin >> site;
		cout << site_key[site] << "\n";

	}
	return 0;
}
