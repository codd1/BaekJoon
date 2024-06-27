#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>> nodes, vector<bool>& visited, vector<int> sort_vec, vector<int>& DFS_result, int num) {
	bool isSameNode = false;		// �̹� �湮�� ������� Ȯ��
	for (int i = 0; i < DFS_result.size(); i++) {
		if (DFS_result[i] == num) {
			isSameNode = true;
			break;
		}
	}

	if (isSameNode == false) {		// �湮���� ���� ��쿡�� ����� push
		DFS_result.push_back(num);
		visited[num] = true;		// + �湮 ǥ��
	}

	for (int i = 0; i < nodes[num].size(); i++) {
		if (visited[nodes[num][i]] == false) {		// ���� ��忡 ����Ǿ��ְ� ���� �湮���� ���� �����
			sort_vec.push_back(nodes[num][i]);		// sort_vec ���Ϳ� push
		}
	}

	if (sort_vec.empty()) {		// ���̻� �湮�� �� �ִ� ��尡 ���ٸ� ����
		return;
	}

	sort(sort_vec.begin(), sort_vec.end());			// ���� (���� ����: ��� ��ȣ�� ���� �� ���� �湮)
	sort_vec.erase(unique(sort_vec.begin(), sort_vec.end()), sort_vec.end());		// �ߺ��� ���� ����

	vector<int> sort_vec_clear;		// �� ���͸� ���� (�Ź� ���ο� ���Ϳ� push�ϵ���)
	for (int i = 0; i < sort_vec.size(); i++) {
		DFS(nodes, visited, sort_vec_clear, DFS_result, sort_vec[i]);	// ���� �� ��� ��ȣ�� ���� �ͺ��� �湮
	}
}

int main() {
	int N;	// ������ ����
	int M;	// ������ ����
	int V;	// Ž���� ������ ������ ��ȣ

	cin >> N >> M >> V;

	vector<vector<int>> nodes(N + 1);		// ��� ��ȣ�� 1 ~ N�̱� ������ N+1 ũ��� �ʱ�ȭ
	vector<bool> visited(N + 1, false);		// �湮 �迭

	queue<int> BFS_search;		// BFS ������ ���� ť

	vector<int> DFS_result;		// DFS Ž�� ���
	vector<int> BFS_result;		// BFS Ž�� ���

	vector<int> sort_vec;		// �湮�� �� �ִ� ��尡 ���� ���� ���, ��� ��ȣ�� ���� �� ���� �湮 -> �� ������ ���� ����

	// �׷����� ���� ����Ʈ�� ����
	int node1, node2;
	for (int i = 1; i <= M; i++) {
		cin >> node1 >> node2;
		nodes[node1].push_back(node2);
		nodes[node2].push_back(node1);
	}

	if (nodes[V].empty()) {		// ���� � ���͵� ������� ���� �����
		cout << V << endl;		// �ش� ��常 ��� �� ����
		cout << V << endl;

		return 0;
	}

	// DFS ����
	visited[V] = true;		// ù ���� �湮 ǥ��
	DFS(nodes, visited, sort_vec, DFS_result, V);

	fill(visited.begin(), visited.end(), false);		// BFS���� �����ϱ� ���� visited ���� false�� �ʱ�ȭ

	// BFS ����
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
					sort_vec.push_back(nodes[front][j]);	// ������ ���� �ϴ� sort_vec�� push
					visited[nodes[front][j]] = true;		// sort_vec�� ������ ���߿� �ᱹ push�ϹǷ� �̸� �湮 ó��
				}
			}

			sort(sort_vec.begin(), sort_vec.end());			// ���� (���� ����: ��� ��ȣ�� ���� �� ���� �湮)

			for (int j = 0; j < sort_vec.size(); j++) {		// ���� �� ��� ��ȣ�� ���� �ͺ��� �湮 (ť�� �߰�)
				BFS_search.push(sort_vec[j]);

				BFS_result.push_back(sort_vec[j]);
			}

			sort_vec.clear();		// ������ ���� �ʿ��ϹǷ� ���� ����� ���� �ʱ�ȭ
		}

		if (!nodes[i].empty() && visited[i] == false) {		// Node i�� �����ϴ� ����̰�, �湮���� ���� ����� push
			BFS_search.push(i);
			visited[i] = true;

			BFS_result.push_back(i);
		}
	}


	// ��� ���
	for (int i = 0; i < DFS_result.size(); i++) {
		cout << DFS_result[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < BFS_result.size(); i++) {
		cout << BFS_result[i] << " ";
	}

	return 0;
}