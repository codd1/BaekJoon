#include <iostream>
#include <vector>

using namespace std;

#define RANDOM_NUM 3

vector<int> num;

void quickSort(int start, int pivot) {
	int end = pivot - 1;

	while (start <= end) {
		// start�� end�� ���� ���, (= ó������ ���� ���)
		if (start == end) {
			int temp = num[pivot];
			if (num[start] < num[pivot]) {		// pivot �����Ͱ� �� Ŭ ���, ���� ������ �����ʿ� �ִ´�
				num.erase(num.begin() + pivot);
				num.insert(num.begin() + start + 1, temp);
			}
			else if (num[start] > num[pivot]) {	// pivot �����Ͱ� �� ���� ���, ���� ������ ���ʿ� �ִ´�
				num.erase(num.begin() + pivot);
				num.insert(num.begin() + start, temp);
			}

			quickSort(0, start);
			quickSort(start + 1, pivot - 1);
		}

		if (num[start] < num[pivot]) {	// start �����Ͱ� pivot �����ͺ��� ������
			start++;		// start�� ���������� 1ĭ �̵�
		}

		if (num[end] > num[pivot]) {	// end �����Ͱ� pivot �����ͺ��� ũ��
			end--;			// end�� �������� 1ĭ �̵�
		}

		if (num[start] > num[pivot] && num[end] < num[pivot]) {		// start �����Ͱ� pivot �����ͺ��� ũ��, end �����Ͱ� pivot �����ͺ��� ���� ���
			swap(num[start], num[end]);		// start �����Ϳ� end ������ swap
			start++;
			end--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// ������ ����
	int K;		// K��° �� ���ϱ�
	
	cin >> N >> K;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		num.push_back(temp);
	}

	// pivot�� �Ź� �� ��� �� ������ ������ ���
	int pivot = N - 1;
	int start = 0;

	quickSort(start, pivot);

	cout << num[K - 1] << endl;

	return 0;
}