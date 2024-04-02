#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;					// ����� ��
	vector<int> P(1000);	// ���� �ð�
	int count = 0;			// �� ���� �ð�

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	int index = 0;
	int temp;

	// ���� ����
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

	// �� ���� �ҿ� �ð� ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			count += P[j];
		}
	}

	cout << count << endl;

	return 0;
}