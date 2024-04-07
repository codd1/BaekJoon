#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& num, int start, int end);

int N;	// ¼öÀÇ °¹¼ö

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<int> num(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	merge(num, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << num[i] << "\n";
	}

	return 0;
}

void merge(vector<int>& num, int start, int end) {
	if (start == end) {
		return;
	}

	int median = (start + end) / 2;

	merge(num, start, median);
	merge(num, median + 1, end);

	vector<int> temp(N);
	int tempIndex = start;

	for (int i = start; i <= end; i++) {
		temp[i] = num[i];
	}

	int point1 = start;
	int point2 = median + 1;

	while (point1 <= median && point2 <= end) {
		if (num[point1] <= num[point2]) {
			temp[tempIndex] = num[point1];
			tempIndex++, point1++;
		}
		else {
			temp[tempIndex] = num[point2];
			tempIndex++, point2++;
		}

		if (point1 > median) {
			for (int i = point2; i <= end; i++) {
				temp[tempIndex++] = num[i];
			}
		}
		else if (point2 > end) {
			for (int i = point1; i <= median; i++) {
				temp[tempIndex++] = num[i];
			}
		}
	}

	for (int i = start; i <= end; i++) {
		num[i] = temp[i];
	}
}