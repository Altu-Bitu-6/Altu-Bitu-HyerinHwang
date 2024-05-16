#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int arr[100001];

void readInput() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int maxLectureLength() {
    return *max_element(arr, arr + n);
}

int sumAllLectures() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

bool canDistribute(int mid) {
    int sum = 0, cnt = 1;  // 블루레이 수, 초기값 1부터 시작
    for (int i = 0; i < n; i++) {
        if (sum + arr[i] > mid) {
            sum = arr[i];
            cnt++;
            if (cnt > m) return false;  // 블루레이 개수 초과시 바로 false 반환
        } else {
            sum += arr[i];
        }
    }
    return true;
}

int findMinimumLength() {
    int l = maxLectureLength();
    int r = sumAllLectures();
    while (l <= r) {
        int mid = (l + r) / 2;
        if (canDistribute(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    readInput();
    cout << findMinimumLength();
    return 0;
}
