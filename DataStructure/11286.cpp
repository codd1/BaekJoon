#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Absolute {
	bool operator()(int num1, int num2) {
		if (abs(num1) == abs(num2)) {		// 절댓값이 같은 경우
			return num1 > num2;		// num1이 클 경우 true를 리턴해 num2와 swap한다.
									// = 더 작은 수(num2)의 우선순위가 높게 잡힘. = 더 작은 값(num2)이 top에 들어감
		}
		else {
			return abs(num1) > abs(num2);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;	// 연산의 갯수
	vector<int> x(100000);
	priority_queue<int, vector<int>, Absolute> queue;	// 우선순위 큐

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < N; i++) {
		if (x[i] == 0) {		// 현재 입력값이 0인 경우
			if (!queue.empty()) {	// 큐가 비어있지 않은 경우 가장 작은 값(top) 출력 및 삭제(pop)
				cout << queue.top() << endl;
				queue.pop();
			}
			else {		// 큐가 비어있는 경우 0 출력
				cout << 0 << endl;
			}
		}
		else {		// 0이 아닌 경우
			queue.push(x[i]);
		}
	}

	return 0;
}