#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& house, vector<vector<bool>> visited, int current_node_x, int current_node_y, int& size) {
	if (current_node_x - 1 >= 0 && current_node_x + 1 < house.size() && current_node_y - 1 >= 0 && current_node_y + 1 < house.size()) {
		// ���� �����¿� ��� �̹� �湮�� ����� ���ư���
		if (visited[current_node_x - 1][current_node_y] == true && visited[current_node_x + 1][current_node_y] == true && visited[current_node_x][current_node_y - 1] == true && visited[current_node_x][current_node_y + 1] == true) {
			visited[current_node_x][current_node_y] = true;
			house[current_node_x][current_node_y] = 0;
			size++;

			return;
		}
	}

	if (house[current_node_x][current_node_y] == 1) {		// 1�� ��쿡�� ���� (= �̿� ���� ���� ���)
		visited[current_node_x][current_node_y] = true;		// �湮�����Ƿ� true�� ����
		house[current_node_x][current_node_y] = 0;			// ��湮���� �ʱ� ���� 0���� ���� (// visited�� ����Ƿ���?)
		size++;												// �湮�����Ƿ� Ƚ��++

		if (current_node_y - 1 >= 0) {				// ���� index ������ �Ѿ�� ��츦 ����� ���� �߰�
			if (visited[current_node_x][current_node_y - 1] == false) {			// ���� Ȯ��
				DFS(house, visited, current_node_x, current_node_y - 1, size);	// ��� ���·� ȣ��
			}
		}

		if (current_node_y + 1 < house.size()) {	// ���� index ������ �Ѿ�� ��츦 ����� ���� �߰�
			if (visited[current_node_x][current_node_y + 1] == false) {			// ���� Ȯ��
				DFS(house, visited, current_node_x, current_node_y + 1, size);	// ��� ���·� ȣ��
			}
		}

		if (current_node_x - 1 >= 0) {				// ���� index ������ �Ѿ�� ��츦 ����� ���� �߰�
			if (visited[current_node_x - 1][current_node_y] == false) {			// ���� Ȯ��
				DFS(house, visited, current_node_x - 1, current_node_y, size);	// ��� ���·� ȣ��
			}
		}

		if (current_node_x + 1 < house.size()) {	// ���� index ������ �Ѿ�� ��츦 ����� ���� �߰�
			if (visited[current_node_x + 1][current_node_y] == false) {			// ���� Ȯ��
				DFS(house, visited, current_node_x + 1, current_node_y, size);	// ��� ���·� ȣ��
			}
		}
	}
}

int main() {
	int N;		// �� ������ (N X N)
	cin >> N;

	vector<vector<int>> house(N, vector<int>(N, 0));			// ����
	vector<vector<bool>> visited(N, vector<bool>(N, true));		// �湮 ���θ� �����ϴ� ����

	char input;		// �� ���ھ� �ޱ� ���� char�� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == '1') {
				house[i][j] = 1;
				visited[i][j] = false;		// ������ 1�� ���Ե� �κи� false�� ���� (1���� 0�� ���� �� ���Ƽ� ù �ʱ�ȭ�� true�� ��)
			}
		}
	}

	vector<int> result;		// ����� ������ ����
	int size = 0;			// ���� ���� �� �� ������ ���� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house[i][j] == 1) {
				DFS(house, visited, i, j, size);
				//printf("DFS ����: house[%d][%d] = %d, size = %d\n", i, j, house[i][j], size);

				result.push_back(size);
				size = 0;

				/*for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {
						cout << house[k][l];
					}
					cout << endl;
				}*/
			}
		}
	}

	cout << result.size() << endl;
	sort(result.begin(), result.end());		// ���� (�������� ������ ����)

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}