#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long n, m;
unsigned long long t[100001];

void readInput() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t, t + n); // 입력 받은 후 바로 정렬
}

unsigned long long calculateMinimumTime() {
    unsigned long long high = m * t[0]; // 최대 시간 설정
    unsigned long long low = 1; // 최소 시간 설정
    unsigned long long ans = 0;

    while (high >= low) {
        unsigned long long mid = (high + low) / 2;
        unsigned long long people = 0;
        for (int i = 0; i < n; i++) {
            people += mid / t[i]; // mid 시간 동안 검사할 수 있는 총 인원 수 계산
        }
        if (people >= m) {
            ans = mid; // 조건을 만족하는 시간 업데이트
            high = mid - 1; // 가능하다면 더 작은 시간을 탐색
        } else {
            low = mid + 1; // 불가능하다면 더 큰 시간을 탐색
        }
    }
    return ans; // 최소 시간 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    readInput();
    cout << calculateMinimumTime();

    return 0;
}
