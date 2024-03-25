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

	vector<int> NGE(1000001);
	vector<int> A(1000001);

	cin >> N;

	int max = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		stack.push(A[i]);

		if (A[i] > max) {
			max = A[i];
		}
	}

	NGE[N] = -1;

	// A = [ 3, 5, 2, 7 ]
	// B = [ 4 3 2 1 2 3 4 ]

	for (int i = N - 1; i > 0; i--) {
		if (A[i] < stack.top()) {		// A) 3 < 5
			NGE[i] = stack.top();
		}
		else {
			if (A[i] < NGE[i + 1]) {	// A) 5 < 2(NGE(3)=7)
				NGE[i] = NGE[i + 1];
			}
			else {
				if (A[i] == max) {
					NGE[i] = -1;
				}
				else {		// B) 2 = 1(NGE(4)=2)
					for (int j = i + 2; j <= N; j++) {
						if (A[i] < A[j]) {
							NGE[i] = A[j];
							A[i + 1] = A[j];
							break;
						}

						if (j == N) {
							NGE[i] = -1;
						}
					}
				}
			}
		}
		stack.pop();
	}

	for (int i = 1; i <= N; i++) {
		cout << NGE[i] << " ";
	}
	cout << endl;

	return 0;
}