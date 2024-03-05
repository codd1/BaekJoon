#include <iostream>

using namespace std;

int main() {
	int N;		// ����̰� ����ؾ��ϴ� Nų�α׷� ����

	cin >> N;

	int maxDivide = N / 3;	// �ִ�� ���� �� �ִ� ���� ��
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

	if (min == N) {		// 5kg�� 3kg ������ ��Ȯ�ϰ� Nkg�� ���� �� ���� ��� -1 ���
		cout << -1 << endl;
	}
	else {
		cout << min << endl;
	}

	return 0;
}