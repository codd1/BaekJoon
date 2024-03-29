#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// �迭�� ũ��
	cin >> N;

	vector<pair<int, int>> A(500001);		// N���� ���� ��� ����

	for (int i = 0; i < N; i++) {
		cin >> A[i].first;		// first�� �Է°� ����
		A[i].second = i;		// second�� �ε��� ����
	}

	sort(A.begin(), A.begin() + N);		// sort(A.begin(), A.end()); �� ���� ����

	int max = 0;
	for (int i = 0; i < N; i++) {
		if ((A[i].second - i) > max) {	// ���� �� index�� ���� �� index�� �� �� ���� ū ���� ã�´�.
			max = A[i].second - i;
		}
	}

	cout << max + 1<< endl;		// �־��� �ڵ� �󿡼� 1�� �� ����ǹǷ� +1

	return 0;
	
}