#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// ��� ����(Radix Sort)�� �̿��� ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// N���� ��
	cin >> N;

	int maxLength = 0;		// �ִ� �ڸ���
	vector<string> strNum(N);	// N���� �� num (string)

	// ������Ŀ����� 10���� Queue�� �ʿ��ϴ�.
	queue<string> queue[10];

	for (int i = 0; i < N; i++) {
		cin >> strNum[i];

		if (strNum[i].length() > maxLength) {
			maxLength = strNum[i].length();
		}
	}

	// ���� ū ������ �ڸ����� ���� ������ ���ڵ鵵 �ڸ����� �����. (���� ���, 100�� �ִ� ���ڸ�(�ִ� �ڸ���:3) 2�� 002��)
	for (int i = 0; i < N; i++) {
		while (strNum[i].length() < maxLength) {
			strNum[i] = strNum[i].insert(0, "0");
		}
	}

	for (int i = maxLength - 1; i >= 0; i--) {		// ���� �ڸ� ���ں��� ����ؾ��ϴµ�, 123�� ��� 3�� ���� �ڸ��̹Ƿ� maxLength-1(=2)���� 0 ������ �ݺ�
		for (int j = 0; j < N; j++) {
			// ��, ����, ����, ... �ڸ��� �������� queue�� ������ ����
			char temp = strNum[j].at(i) - 48;	// char�� �ƽ�Ű�ڵ�� ǥ�õǱ� ������ -48(=���� 0) �ʿ�
			switch (temp)
			{
			case 0:
				queue[0].push(strNum[j]);
				break;
			case 1:
				queue[1].push(strNum[j]);
				break;
			case 2:
				queue[2].push(strNum[j]);
				break;
			case 3:
				queue[3].push(strNum[j]);
				break;
			case 4:
				queue[4].push(strNum[j]);
				break;
			case 5:
				queue[5].push(strNum[j]);
				break;
			case 6:
				queue[6].push(strNum[j]);
				break;
			case 7:
				queue[7].push(strNum[j]);
				break;
			case 8:
				queue[8].push(strNum[j]);
				break;
			case 9:
				queue[9].push(strNum[j]);
				break;
			default:
				break;
			}
		}

		// ť�� ����� �����͸� strNum ���ͷ� FIFO ������� �ٽ� ����
		for (int j = 0, index = 0; j < 10; j++) {
			while (!queue[j].empty()) {
				strNum[index++] = queue[j].front();
				queue[j].pop();
			}
		}
	}

	// ��� ���
	for (int i = 0; i < N; i++) {
		printf("%d\n", stoi(strNum[i]));
	}
}