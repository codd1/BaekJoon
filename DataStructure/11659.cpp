#include <iostream>

using namespace std;

int main() {
	int N;	// 수의 갯수
	int M;	// 합을 구해야하는 횟수

	cin >> N >> M;

	int sum[100001] = { 0, };

	for (int i = 1; i <= N; i++) {
		//cin >> sum[i];
		scanf_s("%d", &sum[i]);

		sum[i] = sum[i - 1] + sum[i];
	}

	int from, to;

	for (int i = 0; i < M; i++) {
		//cin >> from >> to;
		scanf_s("%d %d", &from, &to);
		//cout << sum[to] - sum[from - 1] << endl;
		printf("%d\n", sum[to] - sum[from - 1]);
	}

	return 0;
}