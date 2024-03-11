#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;		// ���� ����
	int input[2000] = { 0, };	// 1 <= A <= 2000
	int count = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	// ����
	sort(input, input + N);

	//int A[2000] = { input[0] };

	//// �ߺ� ���� ����
	//for (int inputIndex = 0, AIndex = 0; inputIndex < N; inputIndex++) {
	//	if (input[inputIndex] != A[AIndex]) {
	//		AIndex++;
	//		A[AIndex] = input[inputIndex];
	//	}
	//}

	if (N < 3) {
		cout << count << endl;

		return 0;
	}

	int first = 0, second = 1;
	int index = N - 1;
	int sum = input[first] + input[second];

	// ������ ��� ����ʿ�, first++ ����
	// 5
	// -1 -1 0 1 1
	while (index >= 0) {
		if (sum < input[index] && second <= index + 1) {
			second++;
			sum = input[first] + input[second];
		}
		else {
			if (sum == input[index]) {
				if (second == index) {
					second++;
					sum = input[first] + input[second];
					continue;
				}
				else if (first == index) {
					first = 1;
					second = 2;
					sum = input[first] + input[second];
					continue;
				}
				else {
					count++;
					printf("%d : first = %d, second = %d, sum = %d\n", index, first, second, sum);
				}
			}

			first = 0;
			second = 1;
			index--;
			sum = input[first] + input[second];
		}
	}

	cout << count << endl;

	return 0;
}