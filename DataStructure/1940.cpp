#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;		// ����� ����
	int M;		// ��Ḧ ������ �� ���;��ϴ� ��

	cin >> N >> M;

	int num[15000] = { 0, };

	// �迭�� �Է� ��(����� ������ȣ��) ����
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	// �������� ���� - O(NlogN) ���� �˰����� ��� ��.
	sort(num, num + N);

	int first = 0, second = 1;
	int count = 0;
	int sum = num[first] + num[second];

	// ��������
	while (first < N - 1) {
		if (sum < M) {
			second++;
			sum = num[first] + num[second];
		}
		else {		// sum == N || sum > N
			if (sum == M) {
				count++;
			}
			// ���ĵ� �����̹Ƿ�, sum���� ���ų� ū ��� ���̻� ū ���� ���ؼ� ���� �ʿ� X
			first++;
			second = first + 1;
			sum = num[first] + num[second];
		}
	}

	cout << count << endl;

	return 0;
}