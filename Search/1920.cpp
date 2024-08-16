#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int M;
	cin >> M;

	vector<int> input(M + 1);

	for (int i = 1; i <= M; i++) {
		cin >> input[i];
	}

	sort(A.begin() + 1, A.end());		// ���� Ž���� ���� �������� ���� (O(nlogn))
										// A[1] ~ A[N]�̹Ƿ� begin() + 1���� end()���� ����

	int start = 1;
	int end = N;
	int median = (start + end) / 2;

	bool result = false;

	for (int i = 1; i <= M; i++) {
		start = 1;
		end = N;

		result = false;

		// ���� Ž��
		while (start <= end) {
			median = (start + end) / 2;

			if (A[median] == input[i]) {
				result = true;
				break;
			}
			else if (input[i] > A[median]) {
				start = median + 1;
			}
			else {
				end = median - 1;
			}
		}

		cout << result << "\n";
	}
}