#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>> nodes, vector<bool>& visited, int start);
void BFS(vector<vector<int>> nodes, vector<bool>& visited, int start);

int main() {
	int N, M, V;		// 정점의 갯수 N, 간선의 갯수 M, 탐색을 시작할 정점의 번호 V

	cin >> N >> M >> V;

	vector<vector<int>> nodes(N + 1);
	vector<bool> visited(N + 1, false);

	int node1, node2;
	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2;
		nodes[node2].push_back(node1);
		nodes[node1].push_back(node2);
	}

	// "단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문"
	for (int i = 1; i < N + 1; i++) {
		sort(nodes[i].begin(), nodes[i].end());
	}

	DFS(nodes, visited, V);

	cout << endl;

	visited.assign(N + 1, false);		// 다시 visited를 false로 초기화
	BFS(nodes, visited, V);
}

void DFS(vector<vector<int>> nodes, vector<bool>& visited, int start) {
	cout << start << " ";

	visited[start] = true;

	for (int i = 0; i < nodes[start].size(); i++) {
		if (visited[nodes[start][i]] == false) {
			DFS(nodes, visited, nodes[start][i]);
		}
	}
}

void BFS(vector<vector<int>> nodes, vector<bool>& visited, int start) {
	queue<int> q;

	q.push(start);
	visited[start] = true;

	int top;
	while (!q.empty()) {
		top = q.front();
		cout << top << " ";

		q.pop();

		for (int i = 0; i < nodes[top].size(); i++) {
			if (visited[nodes[top][i]] == false) {
				q.push(nodes[top][i]);
				visited[nodes[top][i]] = true;
			}
		}
	}
}