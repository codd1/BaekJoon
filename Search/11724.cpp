#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// DFS 문제

int main() {
	int N;		// 노드의 개수
	int M;		// 엣지의 개수
	vector<vector<int>> connect;	// 그래프를 인접 리스트로 저장
	vector<bool> visited;			// 방문한 노드를 나타내는 벡터
	stack<int> search;				// DFS 탐색을 위한 Stack
	int count = 0;

	cin >> N >> M;

	connect.resize(N + 1);
	visited = vector<bool>(N + 1, false);		// 크기를 N으로, 원소는 모두 false로 초기화

	int node1, node2;
	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2;
		connect[node1].push_back(node2);
		connect[node2].push_back(node1);
	}

	/*for (int i = 0; i < connect.size(); i++) {
		std::cout << "Node " << i << ": ";
		for (const auto& neighbor : connect[i]) {
			std::cout << neighbor << " ";
		}
		std::cout << std::endl;
	}*/

	int check_node;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == true) {		// 만약 이미 방문한 노드라면, 다음 노드로 넘어감
			continue;
		}

		// DFS
		search.push(i);		// 시작점은 임의로 설정 (나는 1~N 순서대로)
		visited[i] = true;
		check_node = i;

		while (!search.empty()) {				// search 스택이 빌 때까지 반복
			search.pop();		// 바로 pop

			for (int j = 0; j < connect[check_node].size(); j++) {		
				if (visited[connect[check_node][j]] == false) {		// 이전에 push한 노드와 연결된 노드이고, 방문하지 않은 상태라면
					search.push(connect[check_node][j]);			// 스택에 push,
					visited[connect[check_node][j]] = true;			// 방문 체크
				}
			}

			if (!search.empty()) {
				check_node = search.top();		// 다음 체크 노드는 현재 top 노드
			}
		}

		count++;
	}

	cout << count << endl;
	return 0;
}