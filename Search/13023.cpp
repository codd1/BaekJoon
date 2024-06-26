#include <iostream>
#include <vector>

using namespace std;


void DFS(vector<vector<int>>& friends, vector<bool> visited, int num, int size) {		// ��� �Լ��̹Ƿ� ���� �ٲ�� visited, size�� ���� �� ���
	visited[num] = true;
	size++;

	if (size == 5) {			// ���� ����� ģ�� 5���� ã�� ��� ��� ����
		cout << 1 << endl;
		exit(0);
	}

	for (int i = 0; i < friends[num].size(); i++) {
		if (visited[friends[num][i]] == false) {			// ���� �湮���� ���� ģ���� ã�Ƽ�
			DFS(friends, visited, friends[num][i], size);	// DFS �Լ� ����
		}
	}
}

int main() {
	int N, M;	// N: ����� �� / M: ģ�� ������ ��
	cin >> N >> M;

	vector<vector<int>> friends(N);
	vector<bool> visited(N, false);

	int friend1, friend2;
	for (int i = 0; i < M; i++) {
		cin >> friend1 >> friend2;

		friends[friend1].push_back(friend2);	// �Է� �޾Ƽ� ���� ����Ʈ ����
		friends[friend2].push_back(friend1);
	}

	int size;

	for (int i = 0; i < N; i++) {
		size = 0;

		DFS(friends, visited, i, size);		// 0 ~ N-1 ���������� DFS �Լ� ����
	}

	cout << 0 << endl;

	return 0;
}