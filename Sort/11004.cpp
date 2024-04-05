#include <iostream>
#include <vector>

using namespace std;

#define RANDOM_NUM 3

int partition(vector<int> &num, int start, int end);		// pivot을 기준으로 분할
void quickSort(vector<int>& num, int start, int end, int K);		// 퀵 정렬

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;		// 숫자의 갯수
	int K;		// K번째 수 구하기

	cin >> N >> K;

	vector<int> num(N);		// N개의 수

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	quickSort(num, 0, N - 1, K - 1);

	cout << num[K - 1] << endl;

	return 0;
}

void quickSort(vector<int>& num, int start, int end, int K) {
	int pivot = partition(num, start, end);		// pivot 구하기

	if (pivot == K) {	// K번째 수가 pivot이면 바로 답을 알 수 있으므로 return
		return;
	}
	else if (K < pivot) {	// K가 pivot보다 작으면 왼쪽 그룹만 정렬
		quickSort(num, start, pivot - 1, K);
	}
	else {		// K가 pivot보다 크면 오른쪽 그룹만 정렬
		quickSort(num, pivot + 1, end, K);
	}
}

int partition(vector<int>& num, int start, int end) {
	if (start + 1 == end) {		// 범위(start~end) 내에 값이 2개밖에 없을 경우
		if (num[start] > num[end]) {
			swap(num[start], num[end]);
		}
		return end;
	}

	int median = (start + end) / 2;		// 중앙값
	swap(num[start], num[median]);		// 중앙값을 맨 앞으로 옮김 (편의를 위해)
	int pivot = num[start];				// { 중앙값 , start, ..., end }
	
	int i = start + 1, j = end;
	while (i <= j) {
		while (j >= start + 1 && pivot < num[j]) {		// i와 j 만나기 전까지 && pivot보다 작은 수가 나올 때까지 반복
			j--;		// pivot보다 큰 수이면 j 왼쪽으로 이동
		}

		while (i <= end && pivot > num[i]) {	// i와 j 만나기 전까지 && pivot보다 큰 수가 나올 때까지 반복
			i++;		// pivot보다 작은 수이면 i 오른쪽으로 이동
		}

		// 위에서 반복문을 돌렸는데도 i(start)와 j(end)가 만나지 않았다면,
		// i 데이터가 pivot 데이터보다 크고, j 데이터가 pivot 데이터보다 작다는 뜻
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
	return j;		// 최종 pivot 위치 리턴
}