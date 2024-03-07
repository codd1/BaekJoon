#include <iostream>

using namespace std;

int main() {

	// 시간 초과 문제 해결 방법
	// 1. 아래 세 줄 입력
	// 2. cout endl 대신 printf \n 사용하기
	// 이 문제에서는 1, 2번 둘 다 써야 시간 초과가 뜨지 않음
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 표의 크기 N X N
	int M;		// 합을 구해야하는 횟수

	cin >> N >> M;

	int sum[1025][1025] = { 0 };	// N의 최대 크기 1024

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> sum[x][y];

			sum[x][y] = sum[x][y - 1] + sum[x - 1][y] - sum[x - 1][y - 1] + sum[x][y];
		}
	}

	int x1, y1, x2, y2;

	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		printf("%d\n", sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);
	}

	return 0;
}