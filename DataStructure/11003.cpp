#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> Node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 숫자의 갯수
	int L;		// 슬라이딩 윈도우 크기

	cin >> N >> L;

	deque<Node> D;

	int now;

	for (int i = 0; i < N; i++) {
		cin >> now;

		while (D.size() && D.back().first > now) {
			D.pop_back();
		}

		D.push_back(Node(now, i));

		if (D.front().second <= i - L) {
			D.pop_front();
		}

		cout << D.front().first << " ";
	}

	return 0;
}