#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& house, int current_node_x, int current_node_y, int& size) {
	if (current_node_x - 1 >= 0 && current_node_x + 1 < house.size() && current_node_y - 1 >= 0 && current_node_y + 1 < house.size()) {
		// ���� �����¿� ��� �̹� �湮�� ����� ���ư���
		if (house[current_node_x - 1][current_node_y] == 0 && house[current_node_x + 1][current_node_y] == 0 && house[current_node_x][current_node_y - 1] == 0 && house[current_node_x][current_node_y + 1] == 0) {
			house[current_node_x][current_node_y] = 0;
			size++;

			return;
		}
	}

	if (house[current_node_x][current_node_y] == 1) {		// 1�� ��쿡�� ���� (= �̿� ���� ���� ���)
		house[current_node_x][current_node_y] = 0;			// ��湮���� �ʱ� ���� 0���� ���� (// visited�� ����Ƿ���?)
		size++;												// �湮�����Ƿ� Ƚ��++

		if (current_node_y - 1 >= 0) {				// ���� index ������ �Ѿ�� ��츦 ����� ���� �߰�
			if (house[current_node_x][current_node_y - 1] == 1) {			// ���� Ȯ��
				DFS(house, current_node_x, current_node_y - 1, size);	// ��� ���·� ȣ��
			}
		}

		if (current_node_y + 1 < house.size()) {	// ���� index ������ �Ѿ�� ��츦 ����� ���� �߰�
			if (house[current_node_x][current_node_y + 1] == 1) {			// ���� Ȯ��
				DFS(house, current_node_x, current_node_y + 1, size);	// ��� ���·� ȣ��
			}
		}

		if (current_node_x - 1 >= 0) {				// ���� index ������ �Ѿ�� ��츦 ����� ���� �߰�
			if (house[current_node_x - 1][current_node_y] == 1) {			// ���� Ȯ��
				DFS(house, current_node_x - 1, current_node_y, size);	// ��� ���·� ȣ��
			}
		}

		if (current_node_x + 1 < house.size()) {	// ���� index ������ �Ѿ�� ��츦 ����� ���� �߰�
			if (house[current_node_x + 1][current_node_y] == 1) {			// ���� Ȯ��
				DFS(house, current_node_x + 1, current_node_y, size);	// ��� ���·� ȣ��
			}
		}
	}
}

int main() {
	int N;		// �� ������ (N X N)
	cin >> N;

	vector<vector<int>> house(N, vector<int>(N, 0));			// ����

	char input;		// �� ���ھ� �ޱ� ���� char�� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == '1') {
				house[i][j] = 1;
			}
		}
	}

	vector<int> result;		// ����� ������ ����
	int size = 0;			// ���� ���� �� �� ������ ���� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house[i][j] == 1) {
				DFS(house, i, j, size);
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