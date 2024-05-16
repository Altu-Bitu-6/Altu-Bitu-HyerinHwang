#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void readInput(vector<int>& v, int& len) {
    cin >> len;
    v.resize(len);  // 벡터 크기를 미리 설정
    for (int i = 0; i < len; ++i) {
        cin >> v[i];
    }
}

void searchAndPrintResults(const vector<int>& v, int len) {
    int temp;
    while (len--) {
        cin >> temp;
        cout << binary_search(v.begin(), v.end(), temp) << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v;
    int len;
    
    readInput(v, len);
    sort(v.begin(), v.end());
    
    cin >> len;
    searchAndPrintResults(v, len);
}
