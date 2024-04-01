#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;	// N을 string으로 한꺼번에 입력받고,
	cin >> N;

	vector<char> num;

	char input;

	for (int i = 0; i < N.length(); i++) {
		input = N[i];

		if (input == '\n') {
			break;
		}

		num.push_back(input);	// '\n'이 나올 때까지 vector에 저장
	}

	int maxIndex;

	int index = 0;
	int temp = 0;
	while (index < num.size()) {
		maxIndex = max_element(num.begin() + index, num.end()) - num.begin();	// 최댓값이 담긴 iter 리턴

		// 최댓값과 맨 앞 인덱스의 위치를 바꿈.
		temp = num[maxIndex];
		num[maxIndex] = num[index];
		num[index] = temp;

		index++;
	}

	for (int i = 0; i < num.size(); i++) {
		cout << num[i];
	}

	return 0;
}