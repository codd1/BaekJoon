#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>> nodes, vector<bool>& visited, vector<int> sort_vec, vector<int>& DFS_result, int num) {
	bool isSameNode = false;		// 이미 방문한 노드인지 확인
	for (int i = 0; i < DFS_result.size(); i++) {
		if (DFS_result[i] == num) {
			isSameNode = true;
			break;
		}
	}

	if (isSameNode == false) {		// 방문하지 않은 경우에만 결과에 push
		DFS_result.push_back(num);
		visited[num] = true;		// + 방문 표시
	}

	for (int i = 0; i < nodes[num].size(); i++) {
		if (visited[nodes[num][i]] == false) {		// 현재 노드에 연결되어있고 아직 방문하지 않은 노드라면
			sort_vec.push_back(nodes[num][i]);		// sort_vec 벡터에 push
		}
	}

	if (sort_vec.empty()) {		// 더이상 방문할 수 있는 노드가 없다면 리턴
		return;
	}

	sort(sort_vec.begin(), sort_vec.end());			// 정렬 (문제 조건: 노드 번호가 작은 것 먼저 방문)
	sort_vec.erase(unique(sort_vec.begin(), sort_vec.end()), sort_vec.end());		// 중복된 원소 제거

	vector<int> sort_vec_clear;		// 빈 벡터를 보냄 (매번 새로운 벡터에 push하도록)
	for (int i = 0; i < sort_vec.size(); i++) {
		DFS(nodes, visited, sort_vec_clear, DFS_result, sort_vec[i]);	// 정렬 후 노드 번호가 작은 것부터 방문
	}
}

int main() {
	int N;	// 정점의 개수
	int M;	// 간선의 개수
	int V;	// 탐색을 시작할 정점의 번호

	cin >> N >> M >> V;

	vector<vector<int>> nodes(N + 1);		// 노드 번호가 1 ~ N이기 때문에 N+1 크기로 초기화
	vector<bool> visited(N + 1, false);		// 방문 배열

	queue<int> BFS_search;		// BFS 구현을 위한 큐

	vector<int> DFS_result;		// DFS 탐색 결과
	vector<int> BFS_result;		// BFS 탐색 결과

	vector<int> sort_vec;		// 방문할 수 있는 노드가 여러 개인 경우, 노드 번호가 작은 것 먼저 방문 -> 이 조건을 위한 벡터

	// 그래프를 인접 리스트로 구현
	int node1, node2;
	for (int i = 1; i <= M; i++) {
		cin >> node1 >> node2;
		nodes[node1].push_back(node2);
		nodes[node2].push_back(node1);
	}

	if (nodes[V].empty()) {		// 만약 어떤 노드와도 연결되지 않은 노드라면
		cout << V << endl;		// 해당 노드만 출력 후 종료
		cout << V << endl;

		return 0;
	}

	// DFS 구현
	visited[V] = true;		// 첫 노드는 방문 표시
	DFS(nodes, visited, sort_vec, DFS_result, V);

	fill(visited.begin(), visited.end(), false);		// BFS에서 재사용하기 위해 visited 원소 false로 초기화

	// BFS 구현
	int front;

	BFS_search.push(V);
	visited[V] = true;
	BFS_result.push_back(V);
	
	for (int i = 1; i <= N; i++) {
		while (!BFS_search.empty()) {
			front = BFS_search.front();

			BFS_search.pop();

			for (int j = 0; j < nodes[front].size(); j++) {
				if (visited[nodes[front][j]] == false) {
					sort_vec.push_back(nodes[front][j]);	// 정렬을 위해 일단 sort_vec에 push
					visited[nodes[front][j]] = true;		// sort_vec에 넣으면 나중에 결국 push하므로 미리 방문 처리
				}
			}

			sort(sort_vec.begin(), sort_vec.end());			// 정렬 (문제 조건: 노드 번호가 작은 것 먼저 방문)

			for (int j = 0; j < sort_vec.size(); j++) {		// 정렬 후 노드 번호가 작은 것부터 방문 (큐에 추가)
				BFS_search.push(sort_vec[j]);

				BFS_result.push_back(sort_vec[j]);
			}

			sort_vec.clear();		// 정렬할 때만 필요하므로 다음 사용을 위해 초기화
		}

		if (!nodes[i].empty() && visited[i] == false) {		// Node i가 존재하는 노드이고, 방문하지 않은 노드라면 push
			BFS_search.push(i);
			visited[i] = true;

			BFS_result.push_back(i);
		}
	}


	// 결과 출력
	for (int i = 0; i < DFS_result.size(); i++) {
		cout << DFS_result[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < BFS_result.size(); i++) {
		cout << BFS_result[i] << " ";
	}

	return 0;
}