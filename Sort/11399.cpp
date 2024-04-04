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

	int target_index = 1;
	int insert_index = 0;
	int insert_value = P[1];
	bool is_change = false;

	// ���� ����
	while (target_index < N) {
		// ������ ��ġ ã��
		for (int i = 0; i < target_index; i++) {
			if (P[target_index] < P[i]) {
				insert_index = i;
				insert_value = P[target_index];
				is_change = true;
				break;
			}
		}

		// ���� ���(target)�� ��ġ�� �״���� ��� ���� ������� �Ѿ
		if (is_change == false) {
			target_index++;
			continue;
		}

		// target�� �� ��ġ ~ target�� ���� ��ġ���� �ڷ� �� ĭ�� �б�
		for (int i = target_index; i > insert_index; i--) {
			P[i] = P[i - 1];
		}
		// target ���� ��ġ�� target �� �ֱ�
		P[insert_index] = insert_value;

		target_index++;
		is_change = false;
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