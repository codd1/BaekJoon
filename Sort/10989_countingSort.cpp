#include <iostream>
#include <vector>

using namespace std;

// 해당 문제는 메모리 제한이 "8MB"이기 때문에 Counting Sort(계수 정렬)을 사용해야 함.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 수의 갯수 N
	cin >> N;

	int num = 0;	// 입력 값
	vector<int> count(10001, 0);	// 수 count를 위한 벡터
	
	// 입력
	for (int i = 0; i < N; i++) {
		cin >> num;
		count[num]++;
	}

	// count를 0부터 다 돌면서 count가 세어진 인덱스(입력 수)를 출력함.
	for (int i = 0; i <= 10000; i++) {
		if (count[i] != 0) {
			while (count[i] != 0) {
				printf("%d\n", i);
				count[i]--;
			}
		}
	}

	return 0;
}