#include <iostream>
#include <vector>

using namespace std;

// 알파벳 빈도를 계산하는 함수
vector<int> calculateAlphabetFrequency(string s) {
    vector<int> frequency(26, 0);
    
    for (auto c : s) {
        frequency[c - 'A']++;
    }
    
    return frequency;
}

// 두 문자열의 유사성을 검사하는 함수
bool checkSimilarity(string base, string comparison) {
    vector<int> baseFrequency = calculateAlphabetFrequency(base);
    vector<int> comparisonFrequency = calculateAlphabetFrequency(comparison);
    vector<int> difference;
    
    for (int i = 0; i < 26; i++) {
        if (baseFrequency[i] != comparisonFrequency[i]) {
            difference.push_back(baseFrequency[i] - comparisonFrequency[i]);
        }
    }
    
    // 같은 구성을 갖는 경우
    if (difference.empty()) return true;
    // 한 문자를 추가하거나 삭제하는 경우
    if (difference.size() == 1 && abs(difference[0]) == 1) return true;
    // 하나의 문자를 다른 문자로 바꾸는 경우
    if (difference.size() == 2 && abs(difference[0]) == 1 && difference[0] + difference[1] == 0) return true;
    
    return false;
}

// 주어진 문자열과 유사한 문자열의 개수를 세는 함수
int countSimilarStrings(int n, string base, vector<string>& words) {
    int count = 0;
    vector<int> baseFrequency = calculateAlphabetFrequency(base);
    
    for (int i = 0; i < n - 1; i++) {
        if (checkSimilarity(base, words[i])) count++;
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 입력
    int n;
    cin >> n;
    string base;
    cin >> base;
    
    // 문자열 배열 입력
    vector<string> words(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> words[i];
    }
    
    // 결과 출력
    cout << countSimilarStrings(n, base, words);
    
    return 0;
}
