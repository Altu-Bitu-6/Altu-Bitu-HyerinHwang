#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// priority queue를 구성하는 함수
priority_queue<int, vector<int>, greater<int>> constructPriorityQueue(int N) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            pq.push(num);
            if (pq.size() > N) {
                pq.pop();
            }
        }
    }
    return pq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // priority queue를 함수를 통해 생성
    priority_queue<int, vector<int>, greater<int>> pq = constructPriorityQueue(N);

    cout << pq.top();
    return 0;
}
