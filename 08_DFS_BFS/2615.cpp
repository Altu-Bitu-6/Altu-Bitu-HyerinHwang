#include <iostream>
#define MAX 19
using namespace std;

char board[MAX][MAX];
int directions[4][2] = { {0,1},{1,0},{1,1},{-1,1} };
bool visited[MAX][MAX][4][2];

// 깊이 우선 탐색으로 오목을 확인하는 함수
char depthFirstSearch(int row, int col, int dir, char color, int count) {
    visited[row][col][dir][color - '1'] = true;
    int nextRow = row + directions[dir][0];
    int nextCol = col + directions[dir][1];
    
    if (nextRow < 0 || nextRow >= MAX || nextCol < 0 || nextCol >= MAX || board[nextRow][nextCol] != color) {
        if (count == 5) {
            return color;
        } else {
            return '0';
        }
    }
    return depthFirstSearch(nextRow, nextCol, dir, color, count + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 바둑판 정보 입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> board[i][j];
        }
    }

    // 오목 탐색
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (board[j][i] != '0') {
                for (int dir = 0; dir < 4; dir++) {
                    if (visited[j][i][dir][board[j][i] - '1']) continue;
                    if (depthFirstSearch(j, i, dir, board[j][i], 1) != '0') {
                        cout << board[j][i] << '\n' << j + 1 << ' ' << i + 1;
                        return 0;
                    }
                }
            }
        }
    }

    cout << 0;
    return 0;
}
