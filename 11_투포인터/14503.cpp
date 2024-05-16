#include <iostream>
#include <vector>

using namespace std;

const int CLEAN = 2;  // 청소 완료된 칸을 나타내는 상수

// 방향 배열 (북, 동, 남, 서 순서로 이동)
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

int clean(int n, int m, int r, int c, int d, vector<vector<int>> &board) {
    int cnt = 0;  // 청소한 칸의 수

    while(true) {
        // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        if(board[r][c] != CLEAN) {
            cnt++;
        }
        board[r][c] = CLEAN;  // 현재 칸 청소 완료

        bool find = false; // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는가 여부
        for(int i = 0; i < 4; i++) {
            // 반시계 방향으로 90도 회전 후 전진
            int nd = (d-i+3) % 4;
            int nr = r + dy[nd], nc = c + dx[nd];

            if(board[nr][nc] == 0) { // 3-2. 아직 청소되지 않은 빈 칸 발견
                find = true;
                r = nr; c = nc; d = nd;  // 청소기 위치와 방향 갱신
                break;
            }
        }
        if(find) { // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우 1번으로 돌아감
            continue;
        }

        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        int bd = (d+2) % 4;  // 현재 방향의 반대 방향 (뒤쪽)
        int br = r + dy[bd], bc = c + dx[bd];

        // [바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
        // 2-2. 뒤쪽 칸이 벽이라 후진할 수 없는 경우
        if(board[br][bc] == 1) {
            return cnt;  // 청소한 칸의 수를 반환하며 종료
        }
        // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진
        r = br; c = bc;  // 청소기 위치 후진
    }
    return cnt;
}

/*
 * [로봇 청소기 작동]
 * 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
 * 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
 *  2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
 *  2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
 * 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
 *  3-1. 반시계 방향으로 90º 회전한다.
 *  3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
 *  3-3. 1번으로 돌아간다.
*/

int main() {
    int n, m, r, c, d;
    vector<vector<int>> board;

    // 입력
    cin >> n >> m;  // 세로 크기 n, 가로 크기 m
    cin >> r >> c >> d;  // 로봇 청소기의 시작 위치 (r, c)와 시작 방향 d
    board.assign(n, vector<int> (m, 0));  // n x m 크기의 보드 초기화
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];  // 보드 상태 입력 (0: 빈 칸, 1: 벽)
        }
    }

    // 연산 & 출력
    cout << clean(n, m, r, c, d, board);  // 청소한 칸의 수 출력
    
    return 0;
}
