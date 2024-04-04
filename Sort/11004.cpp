#include <iostream>
#include <vector>

using namespace std;

#define RANDOM_NUM 3

vector<int> num;

void quickSort(int start, int pivot) {
	int end = pivot - 1;

	while (start <= end) {
		// start와 end가 만난 경우, (= 처음부터 같은 경우)
		if (start == end) {
			int temp = num[pivot];
			if (num[start] < num[pivot]) {		// pivot 데이터가 더 클 경우, 만난 지점의 오른쪽에 넣는다
				num.erase(num.begin() + pivot);
				num.insert(num.begin() + start + 1, temp);
			}
			else if (num[start] > num[pivot]) {	// pivot 데이터가 더 작을 경우, 만난 지점의 왼쪽에 넣는다
				num.erase(num.begin() + pivot);
				num.insert(num.begin() + start, temp);
			}

			quickSort(0, start);
			quickSort(start + 1, pivot - 1);
		}

		if (num[start] < num[pivot]) {	// start 데이터가 pivot 데이터보다 작으면
			start++;		// start를 오른쪽으로 1칸 이동
		}

		if (num[end] > num[pivot]) {	// end 데이터가 pivot 데이터보다 크면
			end--;			// end를 왼쪽으로 1칸 이동
		}

		if (num[start] > num[pivot] && num[end] < num[pivot]) {		// start 데이터가 pivot 데이터보다 크고, end 데이터가 pivot 데이터보다 작은 경우
			swap(num[start], num[end]);		// start 데이터와 end 데이터 swap
			start++;
			end--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 숫자의 갯수
	int K;		// K번째 수 구하기
	
	cin >> N >> K;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		num.push_back(temp);
	}

	// pivot이 매번 비교 대상 중 마지막 원소일 경우
	int pivot = N - 1;
	int start = 0;

	quickSort(start, pivot);

	cout << num[K - 1] << endl;

	return 0;
}