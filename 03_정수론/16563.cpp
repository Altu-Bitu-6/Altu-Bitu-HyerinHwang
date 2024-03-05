#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define Max 5000000
vector<int> include(Max + 1);

void preprocessInclude() {
    for (int i = 0; i <= Max; ++i) {
        include[i] = i;
    }
    for (int j = 2; j * j <= Max; ++j) {
        if (include[j] == j) {
            for (int k = j * j; k <= Max; k += j) {
                if (include[k] == k)
                    include[k] = j;
            }
        }
    }
}

void primeFactorization(int number) {
    while (number != 1) {
        cout << include[number] << " ";
        number /= include[number];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    preprocessInclude();

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        primeFactorization(num);
    }

    return 0;
}
