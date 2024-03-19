#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// ������ ����
	int L;		// �����̵� ������ ũ��

	/*int D[5000001] = { 0 };
	int A[5000001] = { 0 };*/
	int A[501] = { 0 };
	int D[501] = { 0 };

	cin >> N >> L;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int start = 1 - L + 1;
	int end = 1;
	int min = A[1];
	int index = 1;

	while (end <= N) {
		for (int i = start; i <= end; i++) {
			//printf("%d�� �ε��� - %d ~ %d ��\n", index, start, end);
			if (i <= 0) {
				continue;
			}

			if (A[i] < min) {
				//printf("\t***** A[%d] < %d\n", i, min);
				min = A[i];
			}
		}
		D[index] = min;
		index++;

		min = A[index];

		start++;
		end++;

	}

	for (int i = 1; i <= N; i++) {
		cout << D[i] << " ";
	}

	return 0;
}