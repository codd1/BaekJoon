#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	long long sum[1000001] = { 0 };		// N���� 10^6, sum�� ����Ǵ� �� ����: 10^9 (long long)	
	long long count[1001] = { 0, };		// M���� 10^3
	long long result = 0;

	cin >> N >> M;

	int input;

	for (int i = 1; i <= N; i++) {
		cin >> input;

		sum[i] = (sum[i - 1] + input) % M;

		// �������� 0�� ���Ҵ� M���� ����������� ���̹Ƿ� result++
		if (sum[i] == 0) {
			result++;
		}

		// �������� ���� ����
		for (int j = 0; j < M; j++) {
			if (sum[i] == j) {
				count[j]++;
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (count[i] != 0) {
			result += count[i] * (count[i] - 1) / 2;	// count[i]���� 2������ �̴� ����� �� ��� ����
		}
	}

	cout << result << endl;

}