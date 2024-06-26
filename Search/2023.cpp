#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;		// N�ڸ� ��

// �Ҽ����� �Ǻ����ִ� �Լ�
bool check_prime(int num) {
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

// DFS ����
void DFS(int num, int current_N) {
	if (current_N == N) {			// N��° �ڸ����� �ϼ��߰�,
		if (check_prime(num)) {		// �Ҽ����,
			cout << num << endl;	// ���
		}
		return;
	}

	if (!check_prime(num)) {		// ���� ���ݱ����� ���ڰ� �Ҽ��� �ƴ϶�� return (���� �̴� -> ���̻� ������ �ʿ�X)
		return;
	}

	for (int i = 1; i < 10; i+=2) {
		DFS(num * 10 + i, current_N + 1);
		
	}
}

int main() {
	cin >> N;

	DFS(2, 1);		// DFS(ù ��° �ڸ� ����, ���� �ڸ���)
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}