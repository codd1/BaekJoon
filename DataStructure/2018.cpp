#include <iostream>

using namespace std;

int main() {
	int N;
	int sum = 1;		// 1���� ���ϸ� �Ǵϱ� 1���� ����
	int count = 0;

	cin >> N;

	int start = 1, end = 1;		// 1���� ���ϸ� �Ǵϱ� 1���� ����

	while (end <= N) {
		if (sum > N) {		// start�� �� ĭ ������ (+)
			sum -= start;
			start++;
		}
		else if (sum < N) {	// end�� �� ĭ ������ (+)
			end++;
			sum += end;
		}
		else {		// sum == N
			count++;
			end++;
			sum += end;
		}
	}

	cout << count << endl;

	return 0;
}