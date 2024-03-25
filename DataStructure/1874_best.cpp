#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;		// 수열의 갯수
	int num[100001] = { 0 };		// n개의 수열 저장
	int result[100001] = { 0 };		// 결과 저장
	string str;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	int temp = 1;	// 스택에 push하는 자연수 (1부터 오름차순)
	int numIndex = 1;
	stack<int> stack;

	while (numIndex <= n) {
		if (temp <= num[numIndex]) {		// 오름차순 자연수 <= 현재 수열 값
			for (int i = temp; i <= num[numIndex]; i++, temp++) {		// 오름차순 자연수 == 현재 수열 값까지 반복
				stack.push(i);
				str += "+\n";
				//printf("temp = %d, stack.push(%d)\t\t\t\tnumIndex = %d\n", temp, i, numIndex);

				if (i == num[numIndex]) {	// 같아지면 pop
					stack.pop();
					str += "-\n";
					//printf("i == num[%d] --> stack.pop()\t\t\t\tnumIndex = %d\n", numIndex, numIndex);
					numIndex++;
					temp++;
					break;
				}
			}
		}
		else {			// 오름차순 자연수 > 현재 수열 값
			if ((stack.top()) > num[numIndex]) {
				str = "NO\n";
				break;
			}
			else {
				stack.pop();
				str += "-\n";
				//printf("stack.top(=%d) == num[%d] --> stack.pop()\tnumIndex = %d\n", stack.top(), numIndex, numIndex);
				numIndex++;
				//temp++;
			}
		}
	}

	cout << str << endl;

	return 0;
}