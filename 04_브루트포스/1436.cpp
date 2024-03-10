#include <iostream>
using namespace std;

// 주어진 숫자에서 "666"이 연속으로 등장하는지 확인하는 함수
bool has666(int num) {
    while (num >= 666) {
        if (num % 1000 == 666) // 숫자의 끝 세 자리가 "666"인지 확인
            return true;
        num /= 10;
    }
    return false;
}

// n번째 숫자를 찾는 함수
int findNthNumber(int n) {
    int cnt = 0; // "666"이 연속으로 등장하는 수의 개수
    for (int i = 666;; ++i) {
        if (has666(i)) // "666"이 연속으로 등장하는지 확인
            ++cnt;
        if (n == cnt) // n번째 수인 경우 해당 수 반환
            return i;
    }
}

int main() {
    int n;
    cin >> n; // 찾고자 하는 순서
    cout << findNthNumber(n); // n번째 숫자 출력
    return 0;
}