#include <iostream>
#include <algorithm>
using namespace std;

int N;
int field[10][10];
int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool visited[10][10];
int result = 987654321;

void clearVisited(int row, int col) {
    visited[row][col] = false;

    for (int i = 0; i < 4; i++) {
        int newRow = row + direction[i][0];
        int newCol = col + direction[i][1];
        visited[newRow][newCol] = false;    
    }
}

int calculateSum(int row, int col) {
    for (int i = 0; i < 4; i++) {
        int newRow = row + direction[i][0];
        int newCol = col + direction[i][1];
        if (visited[newRow][newCol]) {
            return -1;
        }   
    }
    int sum = field[row][col];
    for (int i = 0; i < 4; i++) {
        int newRow = row + direction[i][0];
        int newCol = col + direction[i][1];
        visited[newRow][newCol] = true;
        sum += field[newRow][newCol];
    }
    return sum;
}

void explore(int row, int col, int count, int totalCost) {
    if (count == 3) {
        result = min(result, totalCost);
        return;
    }
    for (int i = row; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (visited[i][j]) continue;
            int sum = calculateSum(i, j);
            if (sum != -1) {
                explore(i, j, count + 1, totalCost + sum);
                clearVisited(i, j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
        }
    }

    
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            int sum= calculateSum(i, j);
            explore(i, j, 1, sum);
            clearVisited(i, j);
        }
    }
    cout << result;

    return 0;
}