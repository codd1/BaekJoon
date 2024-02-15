#include <iostream>
using namespace std;

int main() {
    int T;
    int a, b;
    char comma;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> a >> comma >> b;
        cout << a + b << endl;
    }

    return 0;
}