#include <iostream>

using namespace std;

int main() {
	int N;		// 상근이가 배달해야하는 N킬로그램 설탕

	cin >> N;

	int maxDivide = N / 3;	// 최대로 나올 수 있는 봉지 수
	int min = N;
	int sugerCount = 0;

	for (int i = 0; i <= maxDivide; i++) {
		for (int j = 0; j <= maxDivide; j++) {
			if (j * 5 + i * 3 == N) {
				sugerCount = j + i;
			}
			else {
				continue;
			}

			if (min > sugerCount) {
				min = sugerCount;
				sugerCount = 0;
			}
		}
	}

	if (min == N) {		// 5kg과 3kg 봉지로 정확하게 Nkg을 만들 수 없는 경우 -1 출력
		cout << -1 << endl;
	}
	else {
		cout << min << endl;
	}

	return 0;
}