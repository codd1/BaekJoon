#include <iostream>

using namespace std;

int main() {
	int N, M;

	cin >> N;	// 카드의 갯수
	cin >> M;	// 카드의 최대 합

	int sum = 0;
	int best_sum = 0;
	int subtract = 100000;		// M과 카드 세 장을 더한 값의 차

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