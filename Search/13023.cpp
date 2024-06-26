#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int N, M;	// N: ����� �� / M: ģ�� ������ ��
	cin >> N >> M;

	vector<vector<int>> friends(N);
	vector<bool> visited(N, false);
	stack<int> relation;

	int friend1, friend2;
	for (int i = 0; i < M; i++) {
		cin >> friend1 >> friend2;

		friends[friend1].push_back(friend2);
		friends[friend2].push_back(friend1);
	}

	int size = 0;
	int top;
	bool isNext = false;			// �����, �湮���� ���� ģ���� �ִ��� Ȯ��

	for (int i = 0; i < N; i++) {
		size = 0;

		relation.push(i);
		visited[i] = true;

		while (!relation.empty()) {
			top = relation.top();
			relation.pop();
			visited[top] = true;
			isNext = false;

			size++;

			for (int j = 0; j < friends[top].size(); j++) {
				if (visited[friends[top][j]] == false) {
					relation.push(friends[top][j]);		// ����� ģ�� �� ���� �湮���� ���� ģ���� �ִٸ� push

					isNext = true;		// push�����Ƿ� true�� ����
				}
			}

			if (isNext == false && size != 5) {			// ���� �߰��� ģ���� ���ٸ� ���̻� ������ �ȵǴ� ���̹Ƿ� ���� �̴� (size--)
				size--;
			}
		}
		
		if (size == 5) {
			cout << 1 << endl;
			return 0;
		}

		std::fill(visited.begin(), visited.end(), false);		// visited ���� ��� false�� �ʱ�ȭ
	}

	cout << 0 << endl;

	return 0;
}