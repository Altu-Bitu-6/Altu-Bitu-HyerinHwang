/**
 * https://www.acmicpc.net/problem/15665
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int m; // 뽑을 수열의 길이
set<int> nums; // 입력 받은 수 (정렬된 상태, 중복 없음)
vector<int> sequence; // 생성된 수열을 저장할 벡터

/**
 * 생성된 수열을 출력한다.
*/
void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << ' ';
    }
    cout << '\n';
    return;
}

/**
 * 입력 받은 수로부터 중복을 허용한 수열을 생성한다.
 *
 * cnt: 현재까지 뽑은 수의 개수
*/
void backtrack(int cnt) {
    // m개의 수를 모두 뽑은 경우, 수열을 출력하고 종료한다.
    if (cnt == m) {
        printSequence();
        return;
    }

    // 중복을 허용하여 수를 하나씩 뽑아 수열에 저장한다.
    for (int num : nums) {
        sequence[cnt] = num;
        backtrack(cnt + 1);
    }
}

int main() {
    int n; // 입력 받을 수의 개수
    cin >> n >> m; // n개의 수 중에서 m개를 뽑는다.
    while (n--) {
        int num;
        cin >> num;
        nums.insert(num); // 중복 없이 수를 입력받는다.
    }

    // 벡터를 초기화한다.
    sequence.assign(m, 0);

    // 연산을 수행한다.
    backtrack(0);

    return 0;
}
