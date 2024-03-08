#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	long long sum[1000001] = { 0 };		// N범위 10^6, sum에 저장되는 값 범위: 10^9 (long long)	
	long long count[1001] = { 0, };		// M범위 10^3
	long long result = 0;

	cin >> N >> M;

	int input;

	for (int i = 1; i <= N; i++) {
		cin >> input;

		sum[i] = (sum[i - 1] + input) % M;

		// 나머지가 0인 원소는 M으로 나누어떨어지는 것이므로 result++
		if (sum[i] == 0) {
			result++;
		}

		// 나머지값 갯수 세기
		for (int j = 0; j < M; j++) {
			if (sum[i] == j) {
				count[j]++;
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (count[i] != 0) {
			result += count[i] * (count[i] - 1) / 2;	// count[i]에서 2가지를 뽑는 경우의 수 계산 공식
		}
	}

	cout << result << endl;

}