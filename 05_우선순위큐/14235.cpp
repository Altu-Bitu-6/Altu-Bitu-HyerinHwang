#include <bits/stdc++.h>
using namespace std;

// 우선순위 큐에서 가장 작은 수를 출력하는 함수
void visitChildren(priority_queue<int>& pq) {
    if (pq.empty()) {
        cout << -1 << "\n";
        return;
    }
    int t = pq.top();
    pq.pop();
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    priority_queue<int> pq;
    while (n--) {
        int in;
        cin >> in;
        if (in == 0) { // visit children
            visitChildren(pq);
        } else {
            while (in--) {
                int t;
                cin >> t;
                pq.push(t);
            }
        }
    }

    return 0;
}
