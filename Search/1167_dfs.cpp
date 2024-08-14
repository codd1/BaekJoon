#include <iostream>
#include <vector>
#include <utility>		// pair 사용을 위함
#include <algorithm>

using namespace std;

int DFS(vector<vector<pair<int, int>>> nodes, vector<bool>& visited, int start, int& count);

int main() {
	int V;		// 트리의 노드 개수

	cin >> V;

	vector<vector<pair<int, int>>> nodes(V + 1);
	vector<bool> visited(V + 1, false);

	int node_num;				// 노드 번호
	int connected_node_num;		// node_num과 연결된 노드 번호
	int distance;				// 두 노드 사이의 거리

	for (int i = 0; i < V; i++) {
		cin >> node_num;
		while (1) {
			cin >> connected_node_num;
			if (connected_node_num == -1) {		// -1은 더 이상 노드가 없으므로 종료한다는 의미이다.
				break;
			}
			cin >> distance;

			nodes[node_num].push_back(make_pair(connected_node_num, distance));
			nodes[connected_node_num].push_back(make_pair(node_num, distance));
		}
	}

	// nodes 벡터 내 중복된 값 제거
	for (auto& vec : nodes) {
		// 각 노드에 연결된 노드 리스트를 정렬
		sort(vec.begin(), vec.end());
		// 중복된 연결을 제거
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