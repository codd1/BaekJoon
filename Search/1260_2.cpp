#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>> nodes, vector<bool>& visited, int start);
void BFS(vector<vector<int>> nodes, vector<bool>& visited, int start);

int main() {
	int N, M, V;		// ������ ���� N, ������ ���� M, Ž���� ������ ������ ��ȣ V

	cin >> N >> M >> V;

	vector<vector<int>> nodes(N + 1);
	vector<bool> visited(N + 1, false);

	int node1, node2;
	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2;
		nodes[node2].push_back(node1);
		nodes[node1].push_back(node2);
	}

	// "��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮"
	for (int i = 1; i < N + 1; i++) {
		sort(nodes[i].begin(), nodes[i].end());
	}

	DFS(nodes, visited, V);

	cout << endl;

	visited.assign(N + 1, false);		// �ٽ� visited�� false�� �ʱ�ȭ
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