#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, e, f;
	int result_x, result_y;

	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				result_x = x;
				result_y = y;
			}
		}
	}

	cout << result_x << " " << result_y << endl;

	return 0;
}