#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// DFS ����

int main() {
	int N;		// ����� ����
	int M;		// ������ ����
	vector<vector<int>> connect;	// �׷����� ���� ����Ʈ�� ����
	vector<bool> visited;			// �湮�� ��带 ��Ÿ���� ����
	stack<int> search;				// DFS Ž���� ���� Stack
	int count = 0;

	cin >> N >> M;

	connect.resize(N + 1);
	visited = vector<bool>(N + 1, false);		// ũ�⸦ N����, ���Ҵ� ��� false�� �ʱ�ȭ

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
		if (visited[i] == true) {		// ���� �̹� �湮�� �����, ���� ���� �Ѿ
			continue;
		}

		// DFS
		search.push(i);		// �������� ���Ƿ� ���� (���� 1~N �������)
		visited[i] = true;
		check_node = i;

		while (!search.empty()) {				// search ������ �� ������ �ݺ�
			search.pop();		// �ٷ� pop

			for (int j = 0; j < connect[check_node].size(); j++) {		
				if (visited[connect[check_node][j]] == false) {		// ������ push�� ���� ����� ����̰�, �湮���� ���� ���¶��
					search.push(connect[check_node][j]);			// ���ÿ� push,
					visited[connect[check_node][j]] = true;			// �湮 üũ
				}
			}

			if (!search.empty()) {
				check_node = search.top();		// ���� üũ ���� ���� top ���
			}
		}

		count++;
	}

	cout << count << endl;
	return 0;
}