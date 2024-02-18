#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int N = 0;

	scanf("%d", &N);			// 참고로 백준에서 scanf_s 사용 시 컴파일 에러 발생!
								// scanf_s는 VS에서 강제하는 것이지, 표준이 아님.

	// cpp의 cin과 cout을 사용한 경우 "시간 초과" 에러가 나는 문제가 있었음.
	// C의 scanf와 printf가 훨씬 빠르므로 cstdio 헤더를 사용해 해결하기!
	for (int i = 1; i <= N; i++) {
		printf("%d\n", i);
	}

	return 0;
}