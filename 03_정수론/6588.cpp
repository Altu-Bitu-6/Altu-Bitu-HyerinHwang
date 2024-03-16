#include <iostream>

using namespace std;

#define MAX 1000000

int primeArr[MAX] = {0};

// 소수를 체크하는 함수
void primeChk() {
    // 에라토스테네스의 체 알고리즘을 사용하여 소수를 체크함
    for (int i = 2; i * i <= MAX; i++) {
        if (primeArr[i] == 0) {
            for (int j = i * i; j <= MAX; j += i) {
                primeArr[j] = 1;
            }
        }
    }
}

// 소수의 합으로 나타낼 수 있는지 확인하는 함수
bool goldbachConjecture(int n) {
    // 주어진 수를 소수의 합으로 나타낼 수 있는지 확인함
    for (int a = 3; a <= n; a += 2) {
        // a가 소수이고 n-a도 소수인 경우
        if (primeArr[a] == 0 && primeArr[n - a] == 0) {
            // 결과를 출력하고 true 반환
            cout << n << " = " << a << " + " << n - a << "\n";
            return true;
        }
    }
    // 주어진 수를 소수의 합으로 나타낼 수 없는 경우
    cout << "Goldbach's conjecture is wrong.\n";
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    primeChk(); // 소수 체크 함수 호출

    // 입력을 계속 받아오고 결과를 출력함
    while (1) {
        cin >> n;
        if (n == 0) {
            break; // 0을 입력하면 종료
        }

        goldbachConjecture(n); // 소수의 합으로 나타낼 수 있는지 확인하는 함수 호출
    }

    return 0;
}
