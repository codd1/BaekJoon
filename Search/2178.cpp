#include <iostream>
#include <vector>
#include <queue>
#include <utility>		// pair

using namespace std;

int main() {
	int N, M;		// N X M 크기의 미로
	cin >> N >> M;

	vector<vector<int>> maze(N + 2, vector<int>(M + 2, 0));			// 미로 배열
	vector<vector<bool>> visited(N + 2, vector<bool>(M + 2, 0));	// 방문 여부
	queue<pair<int, int>> q;		// BFS 구현을 위한 큐 (x,y 좌표를 넣기 위해 pair로 정의)

	vector<vector<int>> count(N + 1, vector<int>(M + 1, 0));		// 해당 노드까지의 방문 횟수 카운팅

	// 입력
	char input;		// 각각의 수들은 "붙어서" 입력으로 주어지므로 char 타입 이용
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input;
			if (input == '1') {
				maze[i][j] = 1;
			}
		}
	}

	// 초기값 큐에 push ((1,1)이 출발지점)
	q.push(make_pair(1, 1));
	visited[1][1] = true;
	count[1][1]++;			// 출발하면서 방문하므로 횟수+1

	int x, y;

	while (!q.empty()) {
		x = q.front().first;	// 현재 노드의 x 좌표
		y = q.front().second;	// 현재 노드의 y 좌표

		q.pop();

		if (maze[x - 1][y] == 1) {			// 현재 노드(front) 기준 상측 확인
			if (visited[x - 1][y] == false) {			// 현재 노드의 위쪽 노드가 아직 방문하지 않은 노드라면
				q.push(make_pair(x - 1, y));				// x-1, y 좌표를 큐에 push
				visited[x - 1][y] = true;				// 방문 표시

				count[x - 1][y] = count[x][y] + 1;		// 위쪽 노드 횟수에 지금 노드의 방문 횟수 + 1을 저장
			}
		}

		if (maze[x + 1][y] == 1) {			// 현재 노드(front) 기준 하측 확인
			if (visited[x + 1][y] == false) {
				q.push(make_pair(x + 1, y));
				visited[x + 1][y] = true;

				count[x + 1][y] = count[x][y] + 1;
			}
		}

		if (maze[x][y - 1] == 1) {			// 현재 노드(front) 기준 좌측 확인
			if (visited[x][y - 1] == false) {
				q.push(make_pair(x, y - 1));
				visited[x][y - 1] = true;

				count[x][y - 1] = count[x][y] + 1;
			}
		}

		if (maze[x][y + 1] == 1) {			// 현재 노드(front) 기준 우측 확인
			if (visited[x][y + 1] == false) {
				q.push(make_pair(x, y + 1));
				visited[x][y + 1] = true;

				count[x][y + 1] = count[x][y] + 1;
			}
		}
	}

	cout << count[N][M] << endl;

	return 0;
}