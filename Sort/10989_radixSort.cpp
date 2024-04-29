#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 기수 정렬(Radix Sort)을 이용한 정렬

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// N개의 수
	cin >> N;

	int maxLength = 0;		// 최대 자릿수
	vector<string> strNum(N);	// N개의 수 num (string)

	// 기수정렬에서는 10개의 Queue가 필요하다.
	queue<string> queue[10];

	for (int i = 0; i < N; i++) {
		cin >> strNum[i];

		if (strNum[i].length() > maxLength) {
			maxLength = strNum[i].length();
		}
	}

	// 가장 큰 숫자의 자릿수에 맞춰 나머지 숫자들도 자릿수를 맞춘다. (예를 들어, 100이 최대 숫자면(최대 자릿수:3) 2는 002로)
	for (int i = 0; i < N; i++) {
		while (strNum[i].length() < maxLength) {
			strNum[i] = strNum[i].insert(0, "0");
		}
	}

	for (int i = maxLength - 1; i >= 0; i--) {		// 일의 자리 숫자부터 계산해야하는데, 123일 경우 3이 일의 자리이므로 maxLength-1(=2)부터 0 순서로 반복
		for (int j = 0; j < N; j++) {
			// 일, 십의, 백의, ... 자릿수 기준으로 queue에 데이터 저장
			char temp = strNum[j].at(i) - 48;	// char는 아스키코드로 표시되기 때문에 -48(=숫자 0) 필요
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

		// 큐에 저장된 데이터를 strNum 벡터로 FIFO 순서대로 다시 저장
		for (int j = 0, index = 0; j < 10; j++) {
			while (!queue[j].empty()) {
				strNum[index++] = queue[j].front();
				queue[j].pop();
			}
		}
	}

	// 결과 출력
	for (int i = 0; i < N; i++) {
		printf("%d\n", stoi(strNum[i]));
	}
}