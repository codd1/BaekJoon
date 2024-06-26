#include <iostream>
#include <vector>

using namespace std;


void DFS(vector<vector<int>>& friends, vector<bool> visited, int num, int size) {		// 재귀 함수이므로 값이 바뀌는 visited, size는 복사 값 사용
	visited[num] = true;
	size++;

	if (size == 5) {			// 서로 연결된 친구 5명을 찾을 경우 즉시 종료
		cout << 1 << endl;
		exit(0);
	}

	for (int i = 0; i < friends[num].size(); i++) {
		if (visited[friends[num][i]] == false) {			// 아직 방문하지 않은 친구만 찾아서
			DFS(friends, visited, friends[num][i], size);	// DFS 함수 실행
		}
	}
}

int main() {
	int N, M;	// N: 사람의 수 / M: 친구 관계의 수
	cin >> N >> M;

	vector<vector<int>> friends(N);
	vector<bool> visited(N, false);

	int friend1, friend2;
	for (int i = 0; i < M; i++) {
		cin >> friend1 >> friend2;

		friends[friend1].push_back(friend2);	// 입력 받아서 인접 리스트 구현
		friends[friend2].push_back(friend1);
	}

	int size;

	for (int i = 0; i < N; i++) {
		size = 0;

		DFS(friends, visited, i, size);		// 0 ~ N-1 순차적으로 DFS 함수 실행
	}

	cout << 0 << endl;

	return 0;
}