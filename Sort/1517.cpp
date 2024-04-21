#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& A, int first, int second);

static int N;	// 수의 갯수
static long count_swap;		// swap 횟수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<int> A(N + 1);	// N개의 수

	// 입력
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	count_swap = 0;

	merge_sort(A, 1, N);

	cout << count_swap << "\n";

	return 0;
}

void merge_sort(vector<int>& A, int start, int end) {
	if (start == end) {
		return;
	}

	int middle = (start + end) / 2;	// 중간 값

	merge_sort(A, start, middle);
	merge_sort(A, middle + 1, end);

	vector<int> tempA(N + 1);	// 임시 벡터
	tempA = A;

	int index1 = start;
	int index2 = middle + 1;

	int i = start;
	while (index1 <= middle && index2 <= end) {
		if (A[index1] < A[index2]) {
			tempA[i] = A[index1];

			index1++, i++;
		}
		else {
			tempA[i] = A[index2];

			count_swap += index2 - i;	// index2가 i로 이동한만큼 swap 수 count

			index2++, i++;
		}
	}

	// 남은 데이터가 있다면 처리
	while (index1 <= middle) {
		tempA[i++] = A[index1++];
	}
	while (index2 <= end) {
		tempA[i++] = A[index2++];
	}

	// 다시 A에 복사
	A = tempA;
}