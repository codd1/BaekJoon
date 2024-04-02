#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;					// 사람의 수
	vector<int> P(1000);	// 인출 시간
	int count = 0;			// 총 인출 시간

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	int index = 0;
	int temp;

	// 삽입 정렬
	while (index < N) {
		for (int i = 0; i < index; i++) {
			if (P[index] < P[i]) {
				temp = P[i];
				P[i] = P[index];
				P[index] = temp;
			}
		}
		index++;
	}

	// 총 인출 소요 시간 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			count += P[j];
		}
	}

	cout << count << endl;

	return 0;
}