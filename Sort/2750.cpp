#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 입력 값의 갯수
	vector<int> vector(1000);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> vector[i];
	}

	int temp;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (vector[j] > vector[j + 1]) {
				temp = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << vector[i] << endl;
	}

	return 0;
}