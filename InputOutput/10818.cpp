#include <iostream>

using namespace std;

int main() {
	int N;

	int num;
	int min;
	int max;

	cin >> N;

	cin >> num;

	// √ ±‚»≠
	min = num;
	max = num;

	for (int i = 0; i < N - 1; i++) {
		cin >> num;

		if (num < min) {
			min = num;
		}
		else if (num > max) {
			max = num;
		}
	}

	cout << min << " " << max << endl;

	return 0;
}