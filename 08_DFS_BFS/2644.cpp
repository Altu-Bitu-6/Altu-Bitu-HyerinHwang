#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 102

int N, targetX, targetY, M;
int visited[MAX_SIZE];
int graph[MAX_SIZE][MAX_SIZE];
queue<int> q;

void bfs(int start) {
    q.push(start);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (graph[currentNode][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = visited[currentNode] + 1;
            }
        }
    }
}

int main() {
    cin >> N >> targetX >> targetY >> M;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    bfs(targetX);

    if (visited[targetY] == 0)
        visited[targetY] = -1;

    cout << visited[targetY];

    return 0;
}
