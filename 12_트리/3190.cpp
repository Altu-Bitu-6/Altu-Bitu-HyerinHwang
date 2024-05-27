#include <iostream>
#include <queue>
using namespace std;

void initialize_map(int map[102][102], int &k) {
    int t1, t2;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> t1 >> t2;
        map[t1 - 1][t2 - 1] = 1;
    }
}

void process_game(int n, int map[102][102], int &l) {
    int cnt = 0, t1;
    char t3;
    int dx[4] = {1, 0, -1, 0}; // 우, 하, 좌, 상
    int dy[4] = {0, 1, 0, -1};
    int dir = 0;
    int x = 0, y = 0;
    queue<pair<int, int>> q;
    bool visit[102][102] = {false};
    q.push(make_pair(x, y));
    cin >> l;

    for (int i = 0; i < l; i++) {
        cin >> t1 >> t3;
        
        while (cnt < t1 || i == l-1) { 
            cnt++;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visit[ny][nx]) {
                if (map[ny][nx] == 1) { // 사과를 먹었을 때
                    map[ny][nx] = 0; // 사과 없애주고
                    q.push(make_pair(nx, ny)); // 몸 좌표에 추가
                    visit[ny][nx] = true; // 몸 있다는걸 좌표 표시
                } else { // 사과 없을 때
                    q.push(make_pair(nx, ny)); 
                    visit[ny][nx] = true; 
                    visit[q.front().second][q.front().first] = false;
                    q.pop();
                }
            } else {
                cout << cnt;
                return;
            }        
            x = nx;
            y = ny;
            if (cnt == t1) {
                if (t3 == 'D') { // 우측 회전
                    dir = (dir + 1) % 4; 
                } else { // 좌측 회전
                    dir = (dir + 3) % 4;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, l;
    int map[102][102] = {0};
    
    cin >> n;
    initialize_map(map, k);
    process_game(n, map, l);

    return 0;
}
