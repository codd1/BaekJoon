#include <iostream>
#include <vector>

using namespace std;

// �ش� ������ �޸� ������ "8MB"�̱� ������ Counting Sort(��� ����)�� ����ؾ� ��.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// ���� ���� N
	cin >> N;

	int num = 0;	// �Է� ��
	vector<int> count(10001, 0);	// �� count�� ���� ����
	
	// �Է�
	for (int i = 0; i < N; i++) {
		cin >> num;
		count[num]++;
	}

	// count�� 0���� �� ���鼭 count�� ������ �ε���(�Է� ��)�� �����.
	for (int i = 0; i <= 10000; i++) {
		if (count[i] != 0) {
			while (count[i] != 0) {
				printf("%d\n", i);
				count[i]--;
			}
		}
	}

	return 0;
}