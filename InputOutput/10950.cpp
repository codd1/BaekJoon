#include <iostream>
using namespace std;

int main() {
    int a, b;
    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> a;
        cin >> b;
        cout << a + b << endl;
    }

    return 0;
}