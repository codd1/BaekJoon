#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;					// 사람의 수
	vector<int> P(1000);	// 인출 시간
	int count = 0;			// 총 인출 시간

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	int target_index = 1;
	int insert_index = 0;
	int insert_value = P[1];
	bool is_change = false;

	// 삽입 정렬
	while (target_index < N) {
		// 삽입할 위치 찾기
		for (int i = 0; i < target_index; i++) {
			if (P[target_index] < P[i]) {
				insert_index = i;
				insert_value = P[target_index];
				is_change = true;
				break;
			}
		}

		// 정렬 대상값(target)의 위치가 그대로일 경우 다음 대상으로 넘어감
		if (is_change == false) {
			target_index++;
			continue;
		}

		// target이 들어갈 위치 ~ target의 현재 위치까지 뒤로 한 칸씩 밀기
		for (int i = target_index; i > insert_index; i--) {
			P[i] = P[i - 1];
		}
		// target 삽입 위치에 target 값 넣기
		P[insert_index] = insert_value;

		target_index++;
		is_change = false;
	}

	// 총 인출 소요 시간 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			count += P[j];
		}
	}

	cout << count << endl;

	return 0;
}