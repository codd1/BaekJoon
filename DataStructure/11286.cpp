#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Absolute {
	bool operator()(int num1, int num2) {
		if (abs(num1) == abs(num2)) {		// ������ ���� ���
			return num1 > num2;		// num1�� Ŭ ��� true�� ������ num2�� swap�Ѵ�.
									// = �� ���� ��(num2)�� �켱������ ���� ����. = �� ���� ��(num2)�� top�� ��
		}
		else {
			return abs(num1) > abs(num2);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;	// ������ ����
	vector<int> x(100000);
	priority_queue<int, vector<int>, Absolute> queue;	// �켱���� ť

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < N; i++) {
		if (x[i] == 0) {		// ���� �Է°��� 0�� ���
			if (!queue.empty()) {	// ť�� ������� ���� ��� ���� ���� ��(top) ��� �� ����(pop)
				cout << queue.top() << endl;
				queue.pop();
			}
			else {		// ť�� ����ִ� ��� 0 ���
				cout << 0 << endl;
			}
		}
		else {		// 0�� �ƴ� ���
			queue.push(x[i]);
		}
	}

	return 0;
}