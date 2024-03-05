#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    cout << findGCD(n1, n2) << "\n" << findLCM(n1, n2);
    return 0;
}
