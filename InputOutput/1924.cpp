#include <iostream>
#include <string>

using namespace std;

int main() {
	int x, y;
	int day = 0;

	cin >> x;
	cin >> y;

	int month_days[12] = { 31, 28, 31,30,31,30,31,31,30,31,30,31 };

	// 입력한 달(=x)의 이전 달까지 모든 day를 더함
	for (int i = 0; i < (x - 1); i++) {
		day += month_days[i];
	}

	// 입력한 달의 day(=y)까지 더함
	day += y;

	string week = "";

	switch (day % 7) {
	case 0:
		week = "SUN";
		break;
	case 1:
		week = "MON";
		break;
	case 2:
		week = "TUE";
		break;
	case 3:
		week = "WED";
		break;
	case 4:
		week = "THU";
		break;
	case 5:
		week = "FRI";
		break;
	case 6:
		week = "SAT";
		break;
	default:
		break;
	}

	cout << week << endl;

	return 0;
}