#include <iostream>

using namespace std;

int n;
int arr[300001];

// 최소 공배수를 계산하는 함수
long long computeLCM() {
    long long res = arr[n - 1];
    for (int i = n - 2; i > -1; i--) {
        if (res % arr[i] == 0)
            continue;
        long long m = res / arr[i] + 1;
        res = arr[i] * m;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long result = computeLCM();

    printf("%lld\n", result);

    return 0;
}
