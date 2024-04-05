#include<iostream>
#define endl "\n"
#define MAX_STAIRS 301

using namespace std;

int num_stairs;
int stairs[MAX_STAIRS];    // 계단을 나타내는 배열
int max_value[MAX_STAIRS]; // 해당 계단까지의 최대 값 배열

int FindMax(int A, int B) {
    if (A > B) return A;
    return B;
}

void ReadInput() {
    cin >> num_stairs;
    for (int i = 1; i <= num_stairs; i++) {
        cin >> stairs[i];
    }
}

void CalculateMaxValue() {
    max_value[1] = stairs[1];
    max_value[2] = stairs[1] + stairs[2];
    max_value[3] = FindMax(stairs[1] + stairs[3], stairs[2] + stairs[3]);
    
    for (int i = 4; i <= num_stairs; i++) {
        max_value[i] = FindMax(max_value[i - 2] + stairs[i], max_value[i - 3] + stairs[i - 1] + stairs[i]);
    }
}

void PrintResult() {
    cout << max_value[num_stairs] << endl;
}

void Solve() {
    ReadInput();
    CalculateMaxValue();
    PrintResult();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Solve();
    
    return 0;
}
