#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;		// N자리 수

// 소수인지 판별해주는 함수
bool check_prime(int num) {
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

// DFS 구현
void DFS(int num, int current_N) {
	if (current_N == N) {			// N번째 자리까지 완성했고,
		if (check_prime(num)) {		// 소수라면,
			cout << num << endl;	// 출력
		}
		return;
	}

	if (!check_prime(num)) {		// 만약 지금까지의 숫자가 소수가 아니라면 return (조건 미달 -> 더이상 진행할 필요X)
		return;
	}

	for (int i = 1; i < 10; i+=2) {
		DFS(num * 10 + i, current_N + 1);
		
	}
}

int main() {
	cin >> N;

	DFS(2, 1);		// DFS(첫 번째 자리 숫자, 현재 자릿수)
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}