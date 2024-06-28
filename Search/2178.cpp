#include <iostream>
#include <vector>
#include <queue>
#include <utility>		// pair

using namespace std;

int main() {
	int N, M;		// N X M ũ���� �̷�
	cin >> N >> M;

	vector<vector<int>> maze(N + 2, vector<int>(M + 2, 0));			// �̷� �迭
	vector<vector<bool>> visited(N + 2, vector<bool>(M + 2, 0));	// �湮 ����
	queue<pair<int, int>> q;		// BFS ������ ���� ť (x,y ��ǥ�� �ֱ� ���� pair�� ����)

	vector<vector<int>> count(N + 1, vector<int>(M + 1, 0));		// �ش� �������� �湮 Ƚ�� ī����

	// �Է�
	char input;		// ������ ������ "�پ" �Է����� �־����Ƿ� char Ÿ�� �̿�
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input;
			if (input == '1') {
				maze[i][j] = 1;
			}
		}
	}

	// �ʱⰪ ť�� push ((1,1)�� �������)
	q.push(make_pair(1, 1));
	visited[1][1] = true;
	count[1][1]++;			// ����ϸ鼭 �湮�ϹǷ� Ƚ��+1

	int x, y;

	while (!q.empty()) {
		x = q.front().first;	// ���� ����� x ��ǥ
		y = q.front().second;	// ���� ����� y ��ǥ

		q.pop();

		if (maze[x - 1][y] == 1) {			// ���� ���(front) ���� ���� Ȯ��
			if (visited[x - 1][y] == false) {			// ���� ����� ���� ��尡 ���� �湮���� ���� �����
				q.push(make_pair(x - 1, y));				// x-1, y ��ǥ�� ť�� push
				visited[x - 1][y] = true;				// �湮 ǥ��

				count[x - 1][y] = count[x][y] + 1;		// ���� ��� Ƚ���� ���� ����� �湮 Ƚ�� + 1�� ����
			}
		}

		if (maze[x + 1][y] == 1) {			// ���� ���(front) ���� ���� Ȯ��
			if (visited[x + 1][y] == false) {
				q.push(make_pair(x + 1, y));
				visited[x + 1][y] = true;

				count[x + 1][y] = count[x][y] + 1;
			}
		}

		if (maze[x][y - 1] == 1) {			// ���� ���(front) ���� ���� Ȯ��
			if (visited[x][y - 1] == false) {
				q.push(make_pair(x, y - 1));
				visited[x][y - 1] = true;

				count[x][y - 1] = count[x][y] + 1;
			}
		}

		if (maze[x][y + 1] == 1) {			// ���� ���(front) ���� ���� Ȯ��
			if (visited[x][y + 1] == false) {
				q.push(make_pair(x, y + 1));
				visited[x][y + 1] = true;

				count[x][y + 1] = count[x][y] + 1;
			}
		}
	}

	cout << count[N][M] << endl;

	return 0;
}