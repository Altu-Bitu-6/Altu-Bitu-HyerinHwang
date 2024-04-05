#include <iostream>
#include <algorithm>
using namespace std;

// 최장 증가 부분 수열의 길이를 구하는 함수
int findLongestIncreasingSubsequenceLength(int arr[], int N) {
    int dp[1001];
    for (int i = 1; i <= N; i++)
        dp[i] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    sort(dp, dp + N + 1);
    return dp[N];
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[1001];
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    printf("%d", findLongestIncreasingSubsequenceLength(arr, N));
    return 0;
}
