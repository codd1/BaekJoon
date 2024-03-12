#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// ���� ����
	int A[2000] = { 0, };	// 1 <= A <= 2000
	int count = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// ����
	sort(A, A + N);

	if (N < 3) {
		cout << count << endl;

		return 0;
	}

	int first = 1, second = 2;
	int index = 0;
	int sum = A[first] + A[second];

	// ��������
	while (index < N) {
		if (sum > A[index]) {
			if (first == N - 2) {	// �� ���ص� '���� ��'�� ���� �ʴ� ���
				index++;
				first = 0;
				second = 1;
			}
			else {
				first++;
				second = first + 1;
			}
		}
		else if (sum < A[index]) {
			if (second == N - 1) {	// ������ ������ ���� ��� first++
				first++;
				second = first + 1;
			}
			else {
				second++;
			}
		}
		else {		// sum == A[index]
			if (first == index) {			// �ڱ� �ڽ��� ������ ���
				first++;
				second = first + 1;
			}
			else if (second == index) {		// �ڱ� �ڽ��� ������ ���
				second++;
			}
			else {		// '���� ��'�� ���
				count++;
				//printf("===%d : first = %d, second = %d, sum = %d\n", index, first, second, sum);
				index++;
				first = 0;
				second = 1;
			}
		}
		sum = A[first] + A[second];
		//printf("%d : first = %d, second = %d, sum = %d\n", index, first, second, sum);
	}

	cout << count << endl;

	return 0;
}