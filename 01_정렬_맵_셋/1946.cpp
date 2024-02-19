#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int maxRecruits(vector<pair<int, int>>& applicants) {
    sort(applicants.begin(), applicants.end(), compare);

    int maxDocumentRank = applicants[0].first;
    int maxRecruits = 1;

    for (int i = 1; i < applicants.size(); ++i) {
        if (applicants[i].first < maxDocumentRank) {
            maxDocumentRank = applicants[i].first;
            maxRecruits++;
        }
    }

    return maxRecruits;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> applicants(N);

        for (int i = 0; i < N; ++i) {
            cin >> applicants[i].first >> applicants[i].second;
        }

        cout << maxRecruits(applicants) << endl;
    }

    return 0;
}