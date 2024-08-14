#include <iostream>
#include <vector>
#include <utility>		// pair ����� ����
#include <algorithm>

using namespace std;

int DFS(vector<vector<pair<int, int>>> nodes, vector<bool>& visited, int start, int& count);

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
		// �� ��忡 ����� ��� ����Ʈ�� ����
		sort(vec.begin(), vec.end());
		// �ߺ��� ������ ����
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
	}

	int max = 0;
	int count = 0;

	for (int i = 1; i <= V; i++) {
		DFS(nodes, visited, i, count);

		if (count > max) {
			max = count;
		}

		count = 0;
	}

	cout << max << endl;

	return 0;
}

int DFS(vector<vector<pair<int, int>>> nodes, vector<bool>& visited, int start, int& count) {
	visited[start] = true;

	int max = 0;
	int max_index = 0;

	for (int i = 0; i < nodes[start].size(); i++) {
		if (visited[nodes[start][i].first] == false) {
			if (nodes[start][i].second > max) {
				max = nodes[start][i].second;
				max_index = i;
			}
		}
	}

	if (max != 0) {
		DFS(nodes, visited, nodes[start][max_index].first, count);
		count += nodes[start][max_index].second;
	}

	return count;
}