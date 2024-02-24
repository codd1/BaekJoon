#include <iostream>

using namespace std;

int main() {
	int N, M;

	cin >> N;	// ī���� ����
	cin >> M;	// ī���� �ִ� ��

	int sum = 0;
	int best_sum = 0;
	int subtract = 100000;		// M�� ī�� �� ���� ���� ���� ��

	int card[100] = { 0, };

	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; i+j < N; j++) {
			for (int k = 1; i+j+k < N; k++) {
				sum = card[i] + card[i+j] + card[i+j+k];
				if (sum == M) {
					best_sum = sum;
				}
				else if (sum < M) {
					if (subtract > M - sum) {
						best_sum = sum;
						subtract = M - sum;
					}
				}
			}
		}
	}

	cout << best_sum << endl;

	return 0;
}