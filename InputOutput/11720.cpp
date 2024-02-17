#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N;
	char num;
	int sum = 0;

	cin >> N;

	for (int i=0; i<N; i++){
		cin >> num;
		sum += num - 48;
	}

	cout << sum << endl;

	return 0;
}