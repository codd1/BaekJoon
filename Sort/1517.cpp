#include <iostream>
#include <vector>

using namespace std;

static vector<int> A;	// N���� ��
static vector<int> tempA;	// �ӽ� ����
static long count_swap;		// swap Ƚ��

void merge_sort(int start, int end);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;	// ���� ����
	cin >> N;

	A = vector<int>(N + 1);
	tempA = vector<int>(N + 1);

	// �Է�
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	count_swap = 0;

	merge_sort(1, N);

	cout << count_swap << "\n";

	return 0;
}

void merge_sort(int start, int end) {
	if (start == end) {
		return;
	}

	int middle = (start + end) / 2;	// �߰� ��

	merge_sort(start, middle);
	merge_sort(middle + 1, end);

	/*
		�� �ð� �ʰ��� �߻��ߴ� ����: auxiliary space (�ڵ忡�� tempA)

		merge_sort�� ����Լ��ε� �Լ��� ȣ���� ������ ����ؼ� tempA�� ���� ������. --> ���� ����� �ƴ�!
		ũ�� N�� ���͸� �ϳ� �����ϰ� 0���� �ʱ�ȭ�ϴ� �͸����ε� �̹� O(N)�� �ð����⵵�̴�.
		�ű⿡ ���� �Լ� merge_sort�� ȣ�� Ƚ���� O(N)�̰� �� ȣ�� �ø��� tempA = A, A = tempA�� ���縦 �����ϴ� �ð����⵵�� O(N)�̹Ƿ�
		��ü �ð����⵵�� O(N^2)�� �Ǿ� �ð� �ʰ��� �߻��ߴ� ���̴�.
	*/

	for (int i = start; i <= end; i++) {
		tempA[i] = A[i];
	}

	int index1 = start;
	int index2 = middle + 1;

	int i = start;
	while (index1 <= middle && index2 <= end) {
		if (tempA[index1] <= tempA[index2]) {
			A[i] = tempA[index1];

			index1++, i++;
		}
		else {
			A[i] = tempA[index2];

			count_swap += index2 - i;	// index2�� i�� �̵��Ѹ�ŭ swap �� count

			index2++, i++;
		}
	}

	// ���� �����Ͱ� �ִٸ� ó��
	while (index1 <= middle) {
		A[i++] = tempA[index1++];
	}
	while (index2 <= end) {
		A[i++] = tempA[index2++];
	}
}