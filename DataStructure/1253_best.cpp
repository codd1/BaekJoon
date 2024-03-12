#include <iostream>
#include <algorithm>

using namespace std;

// ★ 모범답안
// 시간이 1253.cpp보다 1600ms 줄어듦

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;			// 수의 갯수
	int A[2000];	// 수가 담길 배열
	int count = 0;	// '좋은 수' 갯수

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// 입력 값 오름차순 정렬
	sort(A, A + N);

	// 투포인터
	int first, second;

	for (int i = 0; i < N; i++) {		// N번 반복
		first = 0, second = N - 1;

		while (first < second) {
			if (A[i] < A[first] + A[second]) {		// 찾는 값보다 큰 경우 second 뒤로 한 칸
				second--;
			}
			else if (A[i] > A[first] + A[second]) {	// 찾는 값보다 작은 경우 first 앞으로 한 칸
				first++;
			}
			else {
				if (i == first) {		// 합에 first가 포함된 경우 (자기 자신이 포함되면 좋은 수 X)
					first++;
				}
				else if (i == second) {	// 합에 second가 포함된 경우 (자기 자신이 포함되면 좋은 수 X)
					second--;
				}
				else {		// '좋은 수'인 경우
					count++;
					break;		// 다음 수로 넘어감
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}