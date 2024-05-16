#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX_NUM = 100001;  // 문제 내 수열 길이 최댓값 조건

/**
 * 같은 정수를 k개 이하로 포함한 최장 연속 부분 수열의 길이 구하기
 * @param seq 수열
 * @param k 최대 허용 중복 수
 * @param n 수열의 길이
 * @return 최장 연속 부분 수열의 길이
 */
int calcMaxLength(vector<int> seq, int k, int n) {
    // 초기화
    int ans = 1;  // 시작 시점 길이 => 0번째 원소만 포함
    int left = 0, right = 1;  // 부분 수열의 왼쪽, 오른쪽 포인터. 왼쪽포함O ~ 오른쪽포함X
    vector<int> count(MAX_NUM, 0);  // 수열 내 각 숫자의 개수를 저장하는 배열
    count[seq[left]]++;  // left = 0, 해당 원소의 개수 증가

    // 오른쪽 포인터가 수열 끝에 다다를때 까지
    while (right < n) {
        // right를 오른쪽으로 증가하면서 right번째 숫자를 수열에 추가할 수 있을지 판단
        if (count[seq[right]] >= k) { // right에 있는 숫자의 개수가 k이상이면 -> 추가 불가
            count[seq[left]]--;  // left 숫자 개수 감소
            left++;  // left 이동
            continue;  // 다시 right 추가 가능한지 확인
        }

        // right 숫자 추가 가능한 경우
        count[seq[right]]++;  // right 숫자 개수 증가
        right++;  // right 이동
        ans = max(ans, right - left);  // 최대값 갱신
    }

    return ans;  // 최종 최대 길이 반환
}

int main() {
    int n, k;

    // 입력
    cin >> n >> k;
    vector<int> seq(n, 0);  // n 크기의 수열 초기화
    for (int i = 0; i < n; i++) {
        cin >> seq[i];  // 수열 입력
    }

    // 연산 & 출력
    cout << calcMaxLength(seq, k, n);  // 결과 출력

    return 0;
}
