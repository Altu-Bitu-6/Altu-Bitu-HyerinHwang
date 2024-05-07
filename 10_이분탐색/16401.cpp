#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<int> L;

void readInput() {
    cin >> M >> N;
    L.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
}

int findMaxSnackLength() {
    int left = 1, right = *max_element(L.begin(), L.end());
    int snack = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 0;
        for (int length : L) {
            count += length / mid;
        }
        if (count >= M) {
            snack = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return snack;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    readInput();  // 입력 받기
    cout << findMaxSnackLength() << "\n";  // 최대 과자 길이 계산 및 출력

    return 0;
}
