#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;	// ���� ����
	cin >> N;

	vector<int> A(N + 1);
	int count = 0;
	
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	vector<int> sortA(N + 1);
	sortA = A;
	sort(sortA.begin(), sortA.end());

	int first = 1;
	int second = N;
	int temp;

	while (first < second) {
		for (int i = first; i <= second; i++) {
			if (A[i] > A[i + 1]) {
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;

				count++;
				break;
			}
		}

		int i = 1;
		// �Ϻ� ������ �ƴٸ�, first �� ����
		for (; i <= N; i++) {
			if (A[i] == sortA[i]) {
				first = i + 1;
			}
			else {
				break;
			}
		}
		// �Ϻ� ������ �ƴٸ�, second �� ����
		for (; i <= N; i++) {
			if (A[i] == sortA[i]) {
				second = i - 1;
			}
			else {
				break;
			}
		}
	}

	cout << count << '\n';

	return 0;
}