#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;		// 재료의 갯수
	int M;		// 재료를 합쳤을 때 나와야하는 값

	cin >> N >> M;

	int num[15000] = { 0, };

	// 배열에 입력 값(재료의 고유번호들) 저장
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	// 오름차순 정렬 - O(NlogN) 정렬 알고리즘을 써야 함.
	sort(num, num + N);

	int first = 0, second = 1;
	int count = 0;
	int sum = num[first] + num[second];

	// 투포인터
	while (first < N - 1) {
		if (sum < M) {
			second++;
			sum = num[first] + num[second];
		}
		else {		// sum == N || sum > N
			if (sum == M) {
				count++;
			}
			// 정렬된 상태이므로, sum보다 같거나 큰 경우 더이상 큰 값과 더해서 비교할 필요 X
			first++;
			second = first + 1;
			sum = num[first] + num[second];
		}
	}

	cout << count << endl;

	return 0;
}