#include <iostream>
#include <vector>
#include <utility>		// pair ����� ����
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int V;		// Ʈ���� ��� ����

	cin >> V;

	vector<vector<pair<int, int>>> nodes(V + 1);
	vector<bool> visited(V + 1, false);

	int node_num;				// ��� ��ȣ
	int connected_node_num;		// node_num�� ����� ��� ��ȣ
	int distance;				// �� ��� ������ �Ÿ�

	for (int i = 0; i < V; i++) {
		cin >> node_num;

		while (1) {
			cin >> connected_node_num;
			if (connected_node_num == -1) {		// -1�� �� �̻� ��尡 �����Ƿ� �����Ѵٴ� �ǹ��̴�.
				break;
			}
			cin >> distance;

			nodes[node_num].push_back(make_pair(connected_node_num, distance));
			nodes[connected_node_num].push_back(make_pair(node_num, distance));
		}
	}

	// nodes ���� �� �ߺ��� �� ����
	for (auto& vec : nodes) {
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
	}

	queue<int> q;
	vector<int> vec_distance(V + 1, 0);		// ���� ��忡������ index �������� �Ÿ�
	vec_distance[1] = 0;		// ���� ��ȣ�� 1~V���� �Ű����Ƿ� 1���� ����
	visited[1] = true;
	q.push(1);

	int top;
	while (!q.empty()) {		// ť�� �� ������ BFS ����
		top = q.front();
		q.pop();

		for (int i = 0; i < nodes[top].size(); i++) {
			if (visited[nodes[top][i].first] == false) {		// ���� �湮���� ���� �����,
				q.push(nodes[top][i].first);					// ť�� �ְ�
				visited[nodes[top][i].first] = true;			// �湮 üũ
				vec_distance[nodes[top][i].first] = vec_distance[top] + nodes[top][i].second;	// ���� ��忡������ index �������� �Ÿ� ����.
				// ���� ���, 1���� ����ؼ� 3�� ���� �Ǿ��ִٸ� 1�� 3�� �Ÿ��� 2�̹Ƿ� vec_distance[3] = vec_distance[1]+2�� �����Ѵ�.
			}
		}
	}

	// vec_distance[1~V]�� ����� �� �� ���� ū ���� ã�´�.
	int max = 0;
	int max_index = -1;
	for (int i = 1; i <= V; i++) {
		if (max < vec_distance[i]) {
			max = vec_distance[i];
			max_index = i;
		}
	}

	// BFS �� �� �� =======================

	visited.assign(V + 1, false);	// visited 

	vec_distance[max_index] = 0;	// ���� BFS ��꿡�� 1�� �Ÿ��� ���� �־��� ������ �ٽ� ����
	visited[max_index] = true;
	q.push(max_index);

	while (!q.empty()) {
		top = q.front();
		q.pop();

		for (int i = 0; i < nodes[top].size(); i++) {
			if (visited[nodes[top][i].first] == false) {
				q.push(nodes[top][i].first);
				visited[nodes[top][i].first] = true;
				vec_distance[nodes[top][i].first] = vec_distance[top] + nodes[top][i].second;
			}
		}
	}

	max = 0;
	for (int i = 1; i <= V; i++) {
		if (max < vec_distance[i]) {
			max = vec_distance[i];
		}
	}

	cout << max << endl;

	return 0;
}