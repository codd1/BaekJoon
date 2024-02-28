#include <iostream>

using namespace std;

int main() {
	int N;
	int result;

	cin >> N;

	if (N < 666) {
		result = (N - 1) * 1000 + 666;
	}

	cout << result << endl;

	return 0;
}