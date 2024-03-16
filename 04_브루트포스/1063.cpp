#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<char, char> Position; // 좌표를 표현하는 자료구조

/**
 * 킹 또는 돌의 이동을 처리하는 함수
 * @param input 이동 방향을 나타내는 문자열
 * @param x 현재 x 좌표
 * @param y 현재 y 좌표
 * @return 이동 후의 좌표를 반환
 */
Position move(string input, char x, char y) {
    for (char direction : input) {
        if (direction == 'R') {
            x++;
        } else if (direction == 'L') {
            x--;
        } else if (direction == 'B') {
            y--;
        } else {  // (direction == 'T')
            y++;
        }
    }
    return {x, y};
}

/**
 * 두 좌표가 일치하는지 확인하는 함수
 * @param k 킹의 좌표
 * @param s 돌의 좌표
 * @return 두 좌표가 일치하면 true, 아니면 false를 반환
 */
bool isSamePosition(Position k, Position s) {
    return (k.first == s.first && k.second == s.second);
}

/**
 * 체스판의 범위를 넘어가는지 확인하는 함수
 * @param pos 확인할 좌표
 * @return 좌표가 범위를 벗어나지 않으면 true, 벗어나면 false를 반환
 */
bool checkRange(Position pos) {
    if (pos.first < 'A' || pos.first > 'H' || pos.second < '1' || pos.second > '8') {
        return false;
    }
    return true;
}

int main() {
    Position king, stone; // 킹과 돌의 현재 위치
    int numOfMoves;
    string moveDirections;

    // 입력 받기
    cin >> king.first >> king.second >> stone.first >> stone.second >> numOfMoves;

    // 이동 연산 수행
    while (numOfMoves--) {
        cin >> moveDirections; // 이동 방향 입력 받기

        Position nextKing, nextStone;

        // 킹의 이동 처리
        nextKing = move(moveDirections, king.first, king.second);

        // 돌의 이동 처리
        if (isSamePosition(nextKing, stone)) { // 킹과 돌의 위치가 일치하는 경우
            // 돌을 킹과 같은 방향으로 이동시킴
            nextStone = move(moveDirections, stone.first, stone.second);
        } else {
            nextStone = stone;
        }

        // 이동 후 위치가 체스판 안에 있으면 업데이트
        if (checkRange(nextKing) && checkRange(nextStone)) {
            king = nextKing;
            stone = nextStone;
        }
    }

    // 최종 결과 출력
    cout << king.first << king.second << '\n' << stone.first << stone.second;

    return 0;
}
