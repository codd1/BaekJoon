#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 배열의 크기
	cin >> N;

	vector<pair<int, int>> A(500001);		// N개의 값이 담길 벡터

	for (int i = 0; i < N; i++) {
		cin >> A[i].first;		// first에 입력값 저장
		A[i].second = i;		// second에 인덱스 저장
	}

	sort(A.begin(), A.begin() + N);		// sort(A.begin(), A.end()); 는 정렬 실패

	int max = 0;
	for (int i = 0; i < N; i++) {
		if ((A[i].second - i) > max) {	// 정렬 전 index와 정렬 후 index의 차 중 가장 큰 값을 찾는다.
			max = A[i].second - i;
		}
	}

	cout << max + 1<< endl;		// 주어진 코드 상에서 1번 더 실행되므로 +1

	return 0;
	
}