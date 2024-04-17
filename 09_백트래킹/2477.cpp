#include <iostream>

using namespace std;

pair<int, int> li[12]; // 방향과 길이를 저장할 배열

int findArea() { // 육각형 모양의 영역 너비를 구하는 함수
    int big_square; // 큰 사각형의 넓이
    int small_square; // 작은 사각형의 넓이
    for (int i = 0; i < 9; i++) { // 모든 변을 순회
        if (li[i].first == li[i + 2].first && li[i + 1].first == li[i + 3].first) { // 같은 방향이 한 칸을 건너뛰고 나타나는 형태라면
            big_square = (li[i].second + li[i + 2].second) * (li[i + 1].second + li[i + 3].second); // 전체 사각형의 넓이 갱신
            small_square = li[i + 2].second * li[i + 1].second; // 작은 사각형의 넓이(영역이 없는 부분) 갱신
        }
    }
    return big_square - small_square; // 육각형의 영역 너비 반환
}

int main() {
    int k; // 배수를 입력받을 변수
    cin >> k;

    int direction, length;
    for (int i = 0; i < 6; i++) { // 방향과 길이 입력받음
        cin >> direction >> length;
        li[i] = {direction, length}; // 입력값 저장
    }

    for (int i = 0; i < 6; i++) { // 어디서부터 입력이 들어오는지 모르기 때문에 6개 변을 추가해줌
        li[i + 6] = li[i];
    }

    int area = findArea(); // 영역 너비 계산
    cout << k * area << "\n"; // 배수를 곱한 결과 출력
    
    return 0;
}
