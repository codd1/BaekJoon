#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// ������ ũ�� N
	stack<int> stack;

	vector<int> NGE(1000001, -1);	// �⺻������ -1�� �ʱ�ȭ
	vector<int> A(1000001, 0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	stack.push(0);
	
	int stack_size = 0;

	for (int i = 1; i < N; i++) {
		stack_size = stack.size();
		for (int j = 0; (j < stack_size) && A[i] > A[stack.top()]; j++) {
			if (A[stack.top()] < A[i]) {		// stack.top�� �ε����� �ش��ϴ� A������ ũ�� ��ū��
				NGE[stack.top()] = A[i];		// NGE[stack.top()]�� ��ū���� �ִ´�.
				stack.pop();					// top�� ���� pop
			}
		}
		stack.push(i);		// ���������� ���� �ε��� ��ȣ push
	}

	for (int i = 0; i < N; i++) {
		cout << NGE[i] << " ";
	}

	return 0;
}