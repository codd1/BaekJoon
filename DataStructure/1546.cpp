#include <iostream>

using namespace std;

int main() {
	unsigned int N;
	float max = 0.f;
	float arr[1000] = { 0.f, };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	
	float sum = 0.f;

	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] / max * 100.f;

		sum += arr[i];
	}

	float avg = sum / N;

	cout << avg << endl;

	return 0;
}