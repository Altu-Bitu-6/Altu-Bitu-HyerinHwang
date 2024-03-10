#include <iostream>
using namespace std;

// 함수: 이진수 표현에서 1의 개수를 세는 함수
int countSetBits(int num) {
    int cnt = 0;
    while (num > 0) {
        if (num % 2 == 1)
            cnt++;
        num /= 2;
    }
    return cnt;
}

// 함수: 주어진 n과 k에 대해 결과를 계산하는 함수
int calculateAnswer(int n, int k) {
    if (k >= n)
        return 0;
    int answer = 0;
    while (true) {
        int cnt = countSetBits(n);
        // cnt가 k보다 작거나 같아지면 종료
        if (k >= cnt)
            break;
        n++;
        answer++;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    cout << calculateAnswer(n, k);

    return 0;
}