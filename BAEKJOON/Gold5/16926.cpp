#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,r;
int arr[301][301];

// 시계 반대 방향으로 한 번 회전
void rotateOnce() {
    int layers = min(n,m) / 2;

    for (int l = 0; l < layers; l++) {
        // 현재 레이어의 경계 설정
        int r_min = l, r_max = n - 1 - l;
        int c_min = l, c_max = m - 1 - l;

        // 시작점(왼쪽 위 꼭짓점)의 값을 보관
        int temp = arr[r_min][c_min];

        // 1. 위쪽 변: 오른쪽 값을 왼쪽으로 당김
        for (int j = c_min; j < c_max; j++) {
            arr[r_min][j] = arr[r_min][j + 1];
        }

        // 2. 오른쪽 변: 아래쪽 값을 위쪽으로 당김
        for (int i = r_min; i < r_max; i++) {
            arr[i][c_max] = arr[i + 1][c_max];
        }

        // 3. 아래쪽 변: 왼쪽 값을 오른쪽으로 당김
        for (int j = c_max; j > c_min; j--) {
            arr[r_max][j] = arr[r_max][j - 1];
        }

        // 4. 왼쪽 변: 위쪽 값을 아래쪽으로 당김
        for (int i = r_max; i > r_min; i--) {
            arr[i][c_min] = arr[i - 1][c_min];
        }

        // 보관했던 시작점 값을 시작점 바로 아래 칸에 배치
        arr[r_min + 1][c_min] = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    while (r--) {
        rotateOnce();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}