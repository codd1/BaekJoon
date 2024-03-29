#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<char> N(1'000'000'000);	// 정렬할 수 (<= 1,000,000,000)

	int max = 0;
	int i = 0;
	while (cin >> N[i]) {
		if (N[i] > max) {
			max = N[i];
		}
	}

	N[0] = max;

	for (int i = 1; i < N.size(); i++) {
		N[i] = 
	}
	

	return 0;
}