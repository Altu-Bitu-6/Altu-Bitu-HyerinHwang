#include <iostream>
#include <vector>
#include <string>
using namespace std;

void processCommand(vector<int>& arr, const string& cmd, int x) {
    if (cmd == "add") {
        if (arr[x] == 0) arr[x] = 1;
    } else if (cmd == "remove") {
        if (arr[x] == 1) arr[x] = 0;
    } else if (cmd == "check") {
        cout << arr[x] << "\n";
    } else if (cmd == "toggle") {
        arr[x] = (arr[x] == 1) ? 0 : 1;
    } else if (cmd == "all") {
        for (int k = 1; k <= 20; k++) arr[k] = 1;
    } else if (cmd == "empty") {
        fill(arr.begin(), arr.end(), 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr(21, 0);
    int M, x;
    string str;

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (str != "all" && str != "empty") cin >> x;
        processCommand(arr, str, x);
    }

    return 0;
}