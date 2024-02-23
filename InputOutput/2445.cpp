#include <iostream>

using namespace std;

int main() {
	int N;

	cin >> N;

	int star = 0;
	int blank = 2 * N - star;

	for (int i = 0; i < 2 * N - 1; i++) {
		if (i < N) {
			star++;

			for (int j = 0; j < star; j++) {
				cout << "*";
			}

			for (int j = 0; j < 2 * N - (star * 2); j++) {
				cout << " ";
			}

			for (int j = 0; j < star; j++) {
				cout << "*";
			}
		}
		else {
			star--;

			for (int j = 0; j < star; j++) {
				cout << "*";
			}

			for (int j = 0; j < 2 * N - (star * 2); j++) {
				cout << " ";
			}

			for (int j = 0; j < star; j++) {
				cout << "*";
			}
		}
		
		blank = 2 * N - star;

		cout << endl;
	}

	return 0;
}