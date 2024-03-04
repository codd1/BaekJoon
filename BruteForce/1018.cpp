#include <iostream>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	char arr[50][50] = {'T', };

	char blackChess[8][8] = {		// 'B'로 시작하는 체스판
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'
	};

	char whiteChess[8][8] = {		// 'W'로 시작하는 체스판
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'
	};

	// 체스판 입력값 2차원 배열에 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int blackChessCount = 0;	// blackChess와 같은 타일 갯수
	int whiteChessCount = 0;	// whiteChess와 같은 타일 갯수
	int max = 0;

	// 입력한 전체 체스판을 8X8씩 잘라 나눠가면서 한 타일씩 비교
	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M-8; j++) {
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (arr[k + i][l + j] == blackChess[k][l]) {
						blackChessCount++;
						//cout << "Black++ : arr[" << k << "][" << l << "] = " << blackChessCount << endl;
					}
					if (arr[k + i][l + j] == whiteChess[k][l]) {
						whiteChessCount++;
						//cout << "White++ : arr[" << k << "][" << l << "] = " << whiteChessCount << endl;
					}
				}
			}

			// 최대 타일 갯수 저장
			if (blackChessCount > max) {
				max = blackChessCount;
			}

			if (whiteChessCount > max) {
				max = whiteChessCount;
			}

			blackChessCount = 0;
			whiteChessCount = 0;
		}
	}

	// 8X8 체스판(전체 타일 갯수=64개)에서 같은 타일 갯수 빼기
	int result = 64 - max;

	cout << result << endl;

	return 0;
}