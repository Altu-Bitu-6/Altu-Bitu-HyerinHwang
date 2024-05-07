/**
 * https://www.acmicpc.net/problem/14888
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대를 표현할 상수
const int MAX_N = 11; // 수열의 최대 길이
const int ADD = 0, SUB = 1, MUL = 2, DIV = 3; // 덧셈, 뺄셈, 곱셈, 나눗셈을 나타내는 상수
const int EXP_NUM = 4; // 연산자의 종류 개수

int n; // 수열의 길이
int nums[MAX_N]; // 입력한 수열 저장
int expression[EXP_NUM]; // 입력한 연산자 개수 저장
int max_val = -INF, min_val = INF; // 최댓값과 최솟값을 초기화

/**
 * 연산자를 하나씩 선택하여 모든 경우의 수를 탐색한다.
 *
 * cnt: 뽑은 연산자의 개수
 * cur_val: 현재까지의 연산 결과
*/
void backtrack(int cnt, int cur_val) {
    // 모든 연산자를 다 뽑은 경우, 재귀 호출을 종료한다.
    if (cnt == n - 1) {
        // 최댓값과 최솟값을 갱신한다.
        max_val = max(max_val, cur_val);
        min_val = min(min_val, cur_val);
        return;
    }

    // i번째 연산자를 선택한다.
    for (int i = 0; i < EXP_NUM; i++) {
        // 해당 연산자가 0개라면 사용할 수 없다.
        if (expression[i] == 0) {
            continue;
        }

        // 해당 연산자를 사용한다.
        expression[i]--;
        // 선택한 연산자를 사용하여 다음 값을 계산한 후, 재귀 호출한다.
        switch(i) {
            case ADD:
                backtrack(cnt + 1, cur_val + nums[cnt + 1]);
                break;
            case SUB:
                backtrack(cnt + 1, cur_val - nums[cnt + 1]);
                break;
            case MUL:
                backtrack(cnt + 1, cur_val * nums[cnt + 1]);
                break;
            case DIV:
                backtrack(cnt + 1, cur_val / nums[cnt + 1]);
                break;
        }

        // 재귀 호출이 끝나면 해당 연산자를 반납한다.
        expression[i]++;
    }
}

int main() {
    cin >> n; // 수열의 길이를 입력받는다.
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // 수열을 입력받는다.
    }
    for (int i = 0; i < EXP_NUM; i++) {
        cin >> expression[i]; // 각 연산자의 개수를 입력받는다.
    }

    // 연산을 수행한다.
    backtrack(0, nums[0]);

    cout << max_val << '\n' << min_val; // 최댓값과 최솟값을 출력한다.

    return 0;
}