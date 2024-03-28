#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;		// N장의 카드 갯수
	queue<int> queue;

	cin >> N;

	// queue에 데이터 삽입
	for (int i = 1; i <= N; i++) {
		queue.push(i);
	}

	for (int i = 1; queue.size() != 1; i++) {	// queue에 한 장의 카드만 남을 때까지 반복
		if (i % 2 == 1) {	// 홀수번째일 경우, 카드를 버린다.(pop)
			queue.pop();
		}
		else {		// 짝수번째일 경우, 맨 위의 카드(front)를 맨 아래로 내린다.(push)
			queue.push(queue.front());
			queue.pop();
		}
	}

	cout << queue.front() << endl;

	return 0;
}