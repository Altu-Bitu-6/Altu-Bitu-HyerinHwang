#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> x;

bool is_possible(int mid) {
    if (x[0] - 0 > mid || N - x[x.size() - 1] > mid) return false;
    for (int i = 0; i < x.size() - 1; i++) {
        if ((x[i + 1] - x[i]) > mid * 2) return false;
    }
    return true;
}

void readInput() {
    cin >> N >> M;
    x.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> x[i];
    }
}

int findMinimumDistance() {
    int left = 0, right = 1e9 + 2, ret = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_possible(mid)) {
            ret = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    readInput(); // 입력을 읽는 함수

    cout << findMinimumDistance(); // 최소 거리를 계산하고 출력하는 함수
}
