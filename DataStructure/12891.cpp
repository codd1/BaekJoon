#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int S = 0;		// DNA ���ڿ�({��A��, ��C��, ��G��, ��T��}) ����
	unsigned int P = 0;		// DNA ���ڿ����� ��й�ȣ�� ����� �κй��ڿ��� ����
	string DNA;				// DNA ���ڿ�

	unsigned int A = 0;		// �κй��ڿ��� ������ �ּ� ����
	unsigned int C = 0;
	unsigned int G = 0;
	unsigned int T = 0;

	unsigned int countA = 0;	// �������� ���� ���� A,C,G,T ����
	unsigned int countC = 0;
	unsigned int countG = 0;
	unsigned int countT = 0;

	unsigned int count = 0;

	cin >> S >> P >> DNA;
	cin >> A >> C >> G >> T;

	// 0 ~ P-2������ A, C, G, T ���� ���� = first ~ second-1����
	for (int i = 0; i < P-1; i++) {
		if (DNA[i] == 'A') {
			countA++;
		}
		else if (DNA[i] == 'C') {
			countC++;
		}
		else if (DNA[i] == 'G') {
			countG++;
		}
		else if (DNA[i] == 'T') {
			countT++;
		}
	}

	unsigned int first = 0;
	unsigned int second = P - 1;

	// �����찡 ��(S-1)���� �� ������ �ݺ�
	while (second < S) {
		// second ��ġ�� A || C || G || T ++
		if (DNA[second] == 'A') {
			countA++;
		}
		else if (DNA[second] == 'C') {
			countC++;
		}
		else if (DNA[second] == 'G') {
			countG++;
		}
		else if (DNA[second] == 'T') {
			countT++;
		}

		// �κ� ���ڿ��� ��й�ȣ�� ����� �� �ִ� ���
		if (countA >= A && countC >= C && countG >= G && countT >= T) {
			//printf("countA %d / countC %d / countG %d / countT %d\n", countA, countC, countG, countT);
			count++;
		}

		// first ��ġ�� A || C || G || T --
		if (DNA[first] == 'A') {
			countA--;
		}
		else if (DNA[first] == 'C') {
			countC--;
		}
		else if (DNA[first] == 'G') {
			countG--;
		}
		else if (DNA[first] == 'T') {
			countT--;
		}

		// ���� ������� �Ѿ
		first++;
		second++;
	}

	cout << count << endl;

	return 0;
}