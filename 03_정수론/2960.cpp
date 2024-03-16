#include <iostream>
#include <vector>
using namespace std;

int findKthPrime(int n, int k) {
    vector<int> prime(n + 1);

    for (int i = 2; i <= n; i++) {
        prime[i] = i;
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (prime[j] != 0) {
                prime[j] = 0;
                cnt++;
                if (cnt == k) {
                    return j;
                }
            }
        }
    }
    return -1; // 에러 처리: k번째 소수를 찾을 수 없는 경우
}

int main() {
    int n, k;
    cin >> n >> k;

    int kthPrime = findKthPrime(n, k);
    if (kthPrime != -1) {
        cout << kthPrime << '\n';
    } else {
        cout << "Cannot find kth prime." << '\n';
    }

    return 0;
}
