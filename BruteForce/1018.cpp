#include <iostream>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	char arr[50][50] = {'T', };

	char blackChess[8][8] = {		// 'B'�� �����ϴ� ü����
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'
	};

	char whiteChess[8][8] = {		// 'W'�� �����ϴ� ü����
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
		'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
		'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'
	};

	// ü���� �Է°� 2���� �迭�� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int blackChessCount = 0;	// blackChess�� ���� Ÿ�� ����
	int whiteChessCount = 0;	// whiteChess�� ���� Ÿ�� ����
	int max = 0;

	// �Է��� ��ü ü������ 8X8�� �߶� �������鼭 �� Ÿ�Ͼ� ��
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

			// �ִ� Ÿ�� ���� ����
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

	// 8X8 ü����(��ü Ÿ�� ����=64��)���� ���� Ÿ�� ���� ����
	int result = 64 - max;

	cout << result << endl;

	return 0;
}