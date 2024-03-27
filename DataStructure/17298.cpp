#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 수열의 크기 N
	stack<int> stack;

	vector<int> NGE(1000001, -1);	// 기본적으로 -1로 초기화
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
			if (A[stack.top()] < A[i]) {		// stack.top의 인덱스에 해당하는 A값보다 크면 오큰수
				NGE[stack.top()] = A[i];		// NGE[stack.top()]에 오큰수를 넣는다.
				stack.pop();					// top의 값은 pop
			}
		}
		stack.push(i);		// 마지막으로 현재 인덱스 번호 push
	}

	for (int i = 0; i < N; i++) {
		cout << NGE[i] << " ";
	}

	return 0;
}