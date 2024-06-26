#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int N, M;	// N: 사람의 수 / M: 친구 관계의 수
	cin >> N >> M;

	vector<vector<int>> friends(N);
	vector<bool> visited(N, false);
	stack<int> relation;

	int friend1, friend2;
	for (int i = 0; i < M; i++) {
		cin >> friend1 >> friend2;

		friends[friend1].push_back(friend2);
		friends[friend2].push_back(friend1);
	}

	int size = 0;
	int top;
	bool isNext = false;			// 연결된, 방문하지 않은 친구가 있는지 확인

	for (int i = 0; i < N; i++) {
		size = 0;

		relation.push(i);
		visited[i] = true;

		while (!relation.empty()) {
			top = relation.top();
			relation.pop();
			visited[top] = true;
			isNext = false;

			size++;

			for (int j = 0; j < friends[top].size(); j++) {
				if (visited[friends[top][j]] == false) {
					relation.push(friends[top][j]);		// 연결된 친구 중 아직 방문하지 않은 친구가 있다면 push

					isNext = true;		// push했으므로 true로 변경
				}
			}

			if (isNext == false && size != 5) {			// 새로 추가한 친구가 없다면 더이상 연결이 안되는 것이므로 조건 미달 (size--)
				size--;
			}
		}
		
		if (size == 5) {
			cout << 1 << endl;
			return 0;
		}

		std::fill(visited.begin(), visited.end(), false);		// visited 원소 모두 false로 초기화
	}

	cout << 0 << endl;

	return 0;
}