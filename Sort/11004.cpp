#include <iostream>
#include <vector>

using namespace std;

#define RANDOM_NUM 3

int partition(vector<int> &num, int start, int end);		// pivot�� �������� ����
void quickSort(vector<int>& num, int start, int end, int K);		// �� ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;		// ������ ����
	int K;		// K��° �� ���ϱ�

	cin >> N >> K;

	vector<int> num(N);		// N���� ��

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	quickSort(num, 0, N - 1, K - 1);

	cout << num[K - 1] << endl;

	return 0;
}

void quickSort(vector<int>& num, int start, int end, int K) {
	int pivot = partition(num, start, end);		// pivot ���ϱ�

	if (pivot == K) {	// K��° ���� pivot�̸� �ٷ� ���� �� �� �����Ƿ� return
		return;
	}
	else if (K < pivot) {	// K�� pivot���� ������ ���� �׷츸 ����
		quickSort(num, start, pivot - 1, K);
	}
	else {		// K�� pivot���� ũ�� ������ �׷츸 ����
		quickSort(num, pivot + 1, end, K);
	}
}

int partition(vector<int>& num, int start, int end) {
	if (start + 1 == end) {		// ����(start~end) ���� ���� 2���ۿ� ���� ���
		if (num[start] > num[end]) {
			swap(num[start], num[end]);
		}
		return end;
	}

	int median = (start + end) / 2;		// �߾Ӱ�
	swap(num[start], num[median]);		// �߾Ӱ��� �� ������ �ű� (���Ǹ� ����)
	int pivot = num[start];				// { �߾Ӱ� , start, ..., end }
	
	int i = start + 1, j = end;
	while (i <= j) {
		while (j >= start + 1 && pivot < num[j]) {		// i�� j ������ ������ && pivot���� ���� ���� ���� ������ �ݺ�
			j--;		// pivot���� ū ���̸� j �������� �̵�
		}

		while (i <= end && pivot > num[i]) {	// i�� j ������ ������ && pivot���� ū ���� ���� ������ �ݺ�
			i++;		// pivot���� ���� ���̸� i ���������� �̵�
		}

		// ������ �ݺ����� ���ȴµ��� i(start)�� j(end)�� ������ �ʾҴٸ�,
		// i �����Ͱ� pivot �����ͺ��� ũ��, j �����Ͱ� pivot �����ͺ��� �۴ٴ� ��
		if (i < j) {
			swap(num[i], num[j]);
			i++;
			j--;
		}
		else {
			break;
		}
	}

	num[start] = num[j];
	num[j] = pivot;
	return j;		// ���� pivot ��ġ ����
}