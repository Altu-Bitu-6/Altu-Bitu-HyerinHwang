#include <iostream>
#include <algorithm>

using namespace std;

int T, W;
int list[1001];
int dp[31][2][1001];

// 최대 자두 개수 계산하는 함수
int calcMaxPlums() {
    int ans = 0;
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= W; ++j) {
            ans = max(ans, dp[j][i][T]);
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력
    cin >> T >> W;
    for (int i = 1; i <= T; ++i) {
        cin >> list[i];
    }

    for (int j = 0; j <= W; ++j) {
        for (int i = 1; i <= T; ++i) {
            if (j == 0) {
                dp[j][0][i] = dp[j][0][i - 1] + (list[i] == 1);
            } else {
                dp[j][0][i] = max(dp[j][0][i - 1] + (list[i] == 1), dp[j - 1][1][i - 1] + (list[i] == 1));
                dp[j][1][i] = max(dp[j][1][i - 1] + (list[i] == 2), dp[j - 1][0][i - 1] + (list[i] == 2));
            }
        }
    }

    cout << calcMaxPlums() << '\n';

    return 0;
}
