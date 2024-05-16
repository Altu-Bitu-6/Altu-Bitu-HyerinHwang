#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * 먹을 수 있는 초밥 가짓수의 최댓값 구하기
 * n: 회전 초밥 벨트에 놓인 접시의 수
 * d: 초밥의 가짓수
 * k: 연속해서 먹는 접시의 수
 * c: 쿠폰 번호
*/
int calcMaxSushi(vector<int> &belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0);  // 종류별 먹은 초밥의 개수를 저장하는 벡터

    // 쿠폰으로 초밥 하나를 먹음 (쿠폰에 적힌 번호의 초밥)
    int cnt_sushi = 1; // 먹은 초밥의 가짓수, 쿠폰으로 먹었으므로 1로 시작
    sushi[c]++;  // 쿠폰 초밥 먹은 개수 증가

    // 처음부터 연속으로 k개의 초밥 먹기
    for (int i = 0; i < k; i++) {
        // 만약 처음 먹는 종류의 초밥이라면 cnt_sushi 증가
        if (!sushi[belt[i]]) {
            cnt_sushi++;
        }
        sushi[belt[i]]++;  // 해당 초밥 먹은 개수 증가
    }

    int ans = cnt_sushi;  // 초기값 설정 (첫 k개 초밥 먹었을 때의 가짓수)
    // 슬라이딩 윈도우 기법으로 최대 가짓수 계산
    for (int i = k; i < n + k; i++) {  // 슬라이드 윈도우의 끝 포인트
        // 맨 처음 먹은 초밥을 목록에서 제거
        sushi[belt[i - k]]--;
        if (sushi[belt[i - k]] == 0) {  // 해당 초밥 먹은 개수가 0이면
            cnt_sushi--;  // 먹은 초밥의 가짓수 감소
        }

        // 다음 초밥 먹기
        sushi[belt[i % n]]++;  // 벨트는 원형이므로 인덱스를 n으로 나눈 나머지를 사용
        if (sushi[belt[i % n]] == 1) {  // 새로운 종류의 초밥이라면
            cnt_sushi++;  // 먹은 초밥의 가짓수 증가
        }

        // 최댓값으로 답 갱신
        ans = max(ans, cnt_sushi);
    }

    return ans;
}

int main() {
    int n, d, k, c;

    // 입력
    cin >> n >> d  >> k >> c;
    vector<int> belt(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    // 연산 & 출력
    cout << calcMaxSushi(belt, n, d, k, c);

    return 0;
}
