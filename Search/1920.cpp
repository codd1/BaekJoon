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

	sort(A.begin() + 1, A.end());		// 이진 탐색을 위한 오름차순 정렬 (O(nlogn))
										// A[1] ~ A[N]이므로 begin() + 1부터 end()까지 정렬

	int start = 1;
	int end = N;
	int median = (start + end) / 2;

	bool result = false;

	for (int i = 1; i <= M; i++) {
		start = 1;
		end = N;

		result = false;

		// 이진 탐색
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