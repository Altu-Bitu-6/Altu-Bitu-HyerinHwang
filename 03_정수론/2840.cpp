#include <iostream>
#include <vector>

using namespace std;

// 시계방향으로 바퀴에 적어놓은 알파벳 출력
string printWheel(int n, int index, vector<char>& wheel) {
    string ans = "";
    // 바퀴를 돌릴 때와 반대방향으로 출력
    for (int i = index + n; i > index; i--) {
        ans += wheel[i % n];
    }
    return ans;
}

// 행운의 바퀴 반환
string findLuckyWheel(int n, int k, vector<pair<int, char>>& spins) {
    vector<char> wheel(n, '?'); // 바퀴의 모든 알파벳을 '?'로 초기화
    vector<bool> isAvailable(26, false); // 알파벳 사용 여부 체크

    int index = 0; // 화살표가 가리키는 인덱스

    for (int i = 0; i < k; i++) {
        int spinCount = spins[i].first; // 화살표가 가리키는 글자가 변하는 횟수
        char ch = spins[i].second; // 회전을 멈추었을 때 가리키던 글자

        index = (index + spinCount) % n; // 회전한 후 화살표가 가리키는 인덱스

        // 해당 칸이 이미 ch로 채워져 있는 경우 넘어감
        if (wheel[index] == ch) {
            continue;
        }

        // 다른 글자로 채워져있거나 해당 글자가 이미 사용된 알파벳인 경우 '!' 반환
        if (wheel[index] != '?' || isAvailable[ch - 'A']) {
            return "!";
        }

        wheel[index] = ch; // 해당 칸에 글자 적기
        isAvailable[ch - 'A'] = true; // 해당 알파벳이 사용되었으므로 true로 변경
    }

    // 행운의 바퀴를 문자열로 반환
    return printWheel(n, index, wheel);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 받기
    int n, k;
    cin >> n >> k;

    // 회전 정보 저장
    vector<pair<int, char>> spins(k);
    for (int i = 0; i < k; i++) {
        cin >> spins[i].first >> spins[i].second;
    }

    // 연산 및 출력
    cout << findLuckyWheel(n, k, spins);

    return 0;
}
