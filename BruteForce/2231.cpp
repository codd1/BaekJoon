#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	int sum = 0;
	int result = 0;

	cin >> N;

	string strI;

	for (int i = 1; i <= N; i++) {
		strI = to_string(i);
		for (int j = 0; j < strI.length(); j++) {	// �� �ڸ��� ��
			sum += strI[j] - 48;
		}

		if (i + sum == N) {		// ������ Ȯ��
			result = i;
			break;
		}

		sum = 0;
	}

	cout << result << endl;

	return 0;
}