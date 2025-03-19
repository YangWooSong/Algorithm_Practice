#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> arr;
vector<int> arr2;

void merge(int left, int right) {
	if ((right - left) > (N / K)) //�ʿ� ���� ���� ����
		return;

	int mid = (left + right) / 2;

	int leftTemp = left; //���� ������ �ε���
	int rightTemp = mid + 1; //������ ������ �ε���
	int arr2Index = left; //���յ� ������ ������ ��

	//�պ�
	while (leftTemp <= mid && rightTemp <= right) 
	{
		//�������� ���� �ӽ� ���Ϳ� ����
		if (arr[leftTemp] <= arr[rightTemp]) 
			arr2[arr2Index++] = arr[leftTemp++];	
		else arr2[arr2Index++] = arr[rightTemp++];
	}

	int tmp = leftTemp > mid ? rightTemp : leftTemp;
	while (arr2Index <= right) 
		arr2[arr2Index++] = arr[tmp++]; //���� ���� ���� �� ������ �պ�

	for (int leftTemp = left; leftTemp <= right; leftTemp++) 
		arr[leftTemp] = arr2[leftTemp]; //���� ���Ŀ� ����
}

void merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	arr.resize(N);
	arr2.resize(N);

	for (int i = 0; i < N; i++) 
	{
		cin >> arr[i];
	}

	cin >> K;

	merge_sort(0, N - 1);

	for (int i = 0; i < N; i++) 
		cout << arr2[i] << ' ';
}