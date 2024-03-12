#include <iostream>
#include <algorithm>

using namespace std;

// �� ������
// �ð��� 1253.cpp���� 1600ms �پ��

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;			// ���� ����
	int A[2000];	// ���� ��� �迭
	int count = 0;	// '���� ��' ����

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// �Է� �� �������� ����
	sort(A, A + N);

	// ��������
	int first, second;

	for (int i = 0; i < N; i++) {		// N�� �ݺ�
		first = 0, second = N - 1;

		while (first < second) {
			if (A[i] < A[first] + A[second]) {		// ã�� ������ ū ��� second �ڷ� �� ĭ
				second--;
			}
			else if (A[i] > A[first] + A[second]) {	// ã�� ������ ���� ��� first ������ �� ĭ
				first++;
			}
			else {
				if (i == first) {		// �տ� first�� ���Ե� ��� (�ڱ� �ڽ��� ���ԵǸ� ���� �� X)
					first++;
				}
				else if (i == second) {	// �տ� second�� ���Ե� ��� (�ڱ� �ڽ��� ���ԵǸ� ���� �� X)
					second--;
				}
				else {		// '���� ��'�� ���
					count++;
					break;		// ���� ���� �Ѿ
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}