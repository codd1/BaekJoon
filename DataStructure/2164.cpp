#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;		// N���� ī�� ����
	queue<int> queue;

	cin >> N;

	// queue�� ������ ����
	for (int i = 1; i <= N; i++) {
		queue.push(i);
	}

	for (int i = 1; queue.size() != 1; i++) {	// queue�� �� ���� ī�常 ���� ������ �ݺ�
		if (i % 2 == 1) {	// Ȧ����°�� ���, ī�带 ������.(pop)
			queue.pop();
		}
		else {		// ¦����°�� ���, �� ���� ī��(front)�� �� �Ʒ��� ������.(push)
			queue.push(queue.front());
			queue.pop();
		}
	}

	cout << queue.front() << endl;

	return 0;
}