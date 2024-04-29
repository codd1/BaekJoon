#include <iostream>
#include <vector>

using namespace std;

static vector<int> A;	// N개의 수
static vector<int> tempA;	// 임시 벡터
static long count_swap;		// swap 횟수

void merge_sort(int start, int end);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;	// 수의 갯수
	cin >> N;

	A = vector<int>(N + 1);
	tempA = vector<int>(N + 1);

	// 입력
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

	int middle = (start + end) / 2;	// 중간 값

	merge_sort(start, middle);
	merge_sort(middle + 1, end);

	/*
		★ 시간 초과가 발생했던 이유: auxiliary space (코드에서 tempA)

		merge_sort가 재귀함수인데 함수를 호출할 때마다 계속해서 tempA를 새로 선언함. --> 좋은 방법이 아님!
		크기 N의 벡터를 하나 선언하고 0으로 초기화하는 것만으로도 이미 O(N)의 시간복잡도이다.
		거기에 더해 함수 merge_sort의 호출 횟수는 O(N)이고 각 호출 시마다 tempA = A, A = tempA의 복사를 수행하는 시간복잡도가 O(N)이므로
		전체 시간복잡도가 O(N^2)이 되어 시간 초과가 발생했던 것이다.
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

			count_swap += index2 - i;	// index2가 i로 이동한만큼 swap 수 count

			index2++, i++;
		}
	}

	// 남은 데이터가 있다면 처리
	while (index1 <= middle) {
		A[i++] = tempA[index1++];
	}
	while (index2 <= end) {
		A[i++] = tempA[index2++];
	}
}