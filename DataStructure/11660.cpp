#include <iostream>

using namespace std;

int main() {

	// �ð� �ʰ� ���� �ذ� ���
	// 1. �Ʒ� �� �� �Է�
	// 2. cout endl ��� printf \n ����ϱ�
	// �� ���������� 1, 2�� �� �� ��� �ð� �ʰ��� ���� ����
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// ǥ�� ũ�� N X N
	int M;		// ���� ���ؾ��ϴ� Ƚ��

	cin >> N >> M;

	int sum[1025][1025] = { 0 };	// N�� �ִ� ũ�� 1024

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