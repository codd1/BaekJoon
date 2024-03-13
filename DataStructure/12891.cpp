#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int S = 0;		// DNA 문자열({‘A’, ‘C’, ‘G’, ‘T’}) 길이
	unsigned int P = 0;		// DNA 문자열에서 비밀번호로 사용할 부분문자열의 길이
	string DNA;				// DNA 문자열

	unsigned int A = 0;		// 부분문자열에 들어가야할 최소 갯수
	unsigned int C = 0;
	unsigned int G = 0;
	unsigned int T = 0;

	unsigned int countA = 0;	// 투포인터 범위 내의 A,C,G,T 갯수
	unsigned int countC = 0;
	unsigned int countG = 0;
	unsigned int countT = 0;

	unsigned int count = 0;

	cin >> S >> P >> DNA;
	cin >> A >> C >> G >> T;

	// 0 ~ P-2까지의 A, C, G, T 갯수 세기 = first ~ second-1까지
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

	// 윈도우가 끝(S-1)까지 갈 때까지 반복
	while (second < S) {
		// second 위치의 A || C || G || T ++
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

		// 부분 문자열을 비밀번호로 사용할 수 있는 경우
		if (countA >= A && countC >= C && countG >= G && countT >= T) {
			//printf("countA %d / countC %d / countG %d / countT %d\n", countA, countC, countG, countT);
			count++;
		}

		// first 위치의 A || C || G || T --
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

		// 다음 윈도우로 넘어감
		first++;
		second++;
	}

	cout << count << endl;

	return 0;
}