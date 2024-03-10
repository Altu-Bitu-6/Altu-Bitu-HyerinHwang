#include <iostream>

using namespace std;

// 최대공약수를 계산하는 함수
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    // 입력 받기
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 분자와 분모 계산
    int numerator = a * d + b * c;
    int denominator = b * d;

    // 분자와 분모의 최대공약수 구하기
    int divisor = gcd(numerator, denominator);

    // 기약분수로 만들어 출력
    cout << numerator / divisor << " " << denominator / divisor;
    
    return 0;
}
