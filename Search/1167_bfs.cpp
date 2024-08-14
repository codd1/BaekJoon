#include <iostream>
#include <vector>
#include <utility>		// pair 사용을 위함
#include <algorithm>
#include <queue>

using namespace std;

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
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
	}

	queue<int> q;
	vector<int> vec_distance(V + 1, 0);		// 시작 노드에서부터 index 노드까지의 거리
	vec_distance[1] = 0;		// 정점 번호는 1~V까지 매겨지므로 1부터 시작
	visited[1] = true;
	q.push(1);

	int top;
	while (!q.empty()) {		// 큐가 빌 때까지 BFS 실행
		top = q.front();
		q.pop();

		for (int i = 0; i < nodes[top].size(); i++) {
			if (visited[nodes[top][i].first] == false) {		// 아직 방문하지 않은 노드라면,
				q.push(nodes[top][i].first);					// 큐에 넣고
				visited[nodes[top][i].first] = true;			// 방문 체크
				vec_distance[nodes[top][i].first] = vec_distance[top] + nodes[top][i].second;	// 시작 노드에서부터 index 노드까지의 거리 저장.
				// 예를 들어, 1에서 출발해서 3과 연결 되어있다면 1과 3의 거리는 2이므로 vec_distance[3] = vec_distance[1]+2를 저장한다.
			}
		}
	}

	// vec_distance[1~V]에 저장된 값 중 가장 큰 값을 찾는다.
	int max = 0;
	int max_index = -1;
	for (int i = 1; i <= V; i++) {
		if (max < vec_distance[i]) {
			max = vec_distance[i];
			max_index = i;
		}
	}

	// BFS 한 번 더 =======================

	visited.assign(V + 1, false);	// visited 

	vec_distance[max_index] = 0;	// 이전 BFS 계산에서 1과 거리가 가장 멀었던 노드부터 다시 시작
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