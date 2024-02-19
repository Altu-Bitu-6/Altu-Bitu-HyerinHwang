#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> countOutfits(int n) {
    map<string, int> clothes;

    for (int i = 0; i < n; ++i) {
        string name, type;
        cin >> name >> type;
        clothes[type]++;
    }

    return clothes;
}

int calculateTotalCases(map<string, int>& clothes) {
    int totalCases = 1;

    for (auto& pair : clothes) {
        totalCases *= (pair.second + 1);
    }

    return totalCases - 1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        map<string, int> clothes = countOutfits(n);

        cout << calculateTotalCases(clothes) << endl;
    }

    return 0;
}