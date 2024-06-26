#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& house, vector<vector<bool>> visited, int current_node_x, int current_node_y, int& size) {
	if (current_node_x - 1 >= 0 && current_node_x + 1 < house.size() && current_node_y - 1 >= 0 && current_node_y + 1 < house.size()) {
		// 만약 상하좌우 모두 이미 방문한 노드라면 돌아가기
		if (visited[current_node_x - 1][current_node_y] == true && visited[current_node_x + 1][current_node_y] == true && visited[current_node_x][current_node_y - 1] == true && visited[current_node_x][current_node_y + 1] == true) {
			visited[current_node_x][current_node_y] = true;
			house[current_node_x][current_node_y] = 0;
			size++;

			return;
		}
	}

	if (house[current_node_x][current_node_y] == 1) {		// 1일 경우에만 실행 (= 이웃 집이 있을 경우)
		visited[current_node_x][current_node_y] = true;		// 방문했으므로 true로 변경
		house[current_node_x][current_node_y] = 0;			// 재방문하지 않기 위해 0으로 변경 (// visited가 없어도되려나?)
		size++;												// 방문했으므로 횟수++

		if (current_node_y - 1 >= 0) {				// 벡터 index 범위를 넘어가는 경우를 고려해 조건 추가
			if (visited[current_node_x][current_node_y - 1] == false) {			// 좌측 확인
				DFS(house, visited, current_node_x, current_node_y - 1, size);	// 재귀 형태로 호출
			}
		}

		if (current_node_y + 1 < house.size()) {	// 벡터 index 범위를 넘어가는 경우를 고려해 조건 추가
			if (visited[current_node_x][current_node_y + 1] == false) {			// 우측 확인
				DFS(house, visited, current_node_x, current_node_y + 1, size);	// 재귀 형태로 호출
			}
		}

		if (current_node_x - 1 >= 0) {				// 벡터 index 범위를 넘어가는 경우를 고려해 조건 추가
			if (visited[current_node_x - 1][current_node_y] == false) {			// 상측 확인
				DFS(house, visited, current_node_x - 1, current_node_y, size);	// 재귀 형태로 호출
			}
		}

		if (current_node_x + 1 < house.size()) {	// 벡터 index 범위를 넘어가는 경우를 고려해 조건 추가
			if (visited[current_node_x + 1][current_node_y] == false) {			// 하측 확인
				DFS(house, visited, current_node_x + 1, current_node_y, size);	// 재귀 형태로 호출
			}
		}
	}
}

int main() {
	int N;		// 총 단지수 (N X N)
	cin >> N;

	vector<vector<int>> house(N, vector<int>(N, 0));			// 지도
	vector<vector<bool>> visited(N, vector<bool>(N, true));		// 방문 여부를 저장하는 벡터

	char input;		// 한 글자씩 받기 위해 char로 선언
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == '1') {
				house[i][j] = 1;
				visited[i][j] = false;		// 지도에 1로 기입된 부분만 false로 변경 (1보다 0이 많을 것 같아서 첫 초기화를 true로 함)
			}
		}
	}

	vector<int> result;		// 결과를 리턴할 벡터
	int size = 0;			// 같은 단지 내 집 갯수를 세는 변수

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house[i][j] == 1) {
				DFS(house, visited, i, j, size);
				//printf("DFS 실행: house[%d][%d] = %d, size = %d\n", i, j, house[i][j], size);

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
	sort(result.begin(), result.end());		// 정렬 (문제에서 제시한 조건)

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}