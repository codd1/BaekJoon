#include <iostream>

using namespace std;

int main() {
	int A, B;

	cin >> A >> B;

	for (int x = -1000; x <= 1000; x++) {
		if ((x * x + 2 * A * x + B) == 0) {		// x2  + 2Ax + B = 0
			cout << x << " ";
		}
	}

	cout << endl;

	return 0;
}