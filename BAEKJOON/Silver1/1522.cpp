#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int aCount = 0;
	for (char c : s)
	{
		if (c == 'a')
			aCount++;
	}

	if (aCount == 0)
	{
		cout << 0;
		return 0;
	}

	string circleS = s + s;

	//초기 윈도우
	int bCnt = 0;
	for (int i = 0; i < aCount; ++i)
	{
		if (circleS[i] == 'b')
		{
			bCnt++;
		}
	}

	//전체 검사
	int answer = bCnt;
	//i는 새로 들어오는 문자 인덱스
	for (int i = aCount; i < s.size() + aCount; ++i)
	{
		if (circleS[i - aCount] == 'b')	//나가는 문자
			bCnt--;
		if (circleS[i] == 'b')	//새로 들어오는 문자
			bCnt++;
		answer = min(answer, bCnt);
	}

	cout << answer;
	return 0;
}