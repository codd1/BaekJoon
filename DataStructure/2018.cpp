#include <iostream>

using namespace std;

int main() {
	int N;
	int sum = 1;		// 1부터 더하면 되니까 1부터 시작
	int count = 0;

	cin >> N;

	int start = 1, end = 1;		// 1부터 더하면 되니까 1부터 시작

	while (end <= N) {
		if (sum > N) {		// start를 한 칸 앞으로 (+)
			sum -= start;
			start++;
		}
		else if (sum < N) {	// end를 한 칸 앞으로 (+)
			end++;
			sum += end;
		}
		else {		// sum == N
			count++;
			end++;
			sum += end;
		}
	}

	cout << count << endl;

	return 0;
}