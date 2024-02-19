#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int countStringsInSet(unordered_set<string>& S, int M) {
    int count = 0;
    for (int i = 0; i < M; ++i) {
        string str;
        cin >> str;
        if (S.find(str) != S.end()) {
            count++;
        }
    }
    return count;
}

int main() {
    int N, M;
    cin >> N >> M;

    unordered_set<string> S;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        S.insert(str);
    }

    cout << countStringsInSet(S, M) << endl;

    return 0;
}