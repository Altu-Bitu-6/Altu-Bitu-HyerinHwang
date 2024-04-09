#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 101

int num_vertices, num_edges;
int edge_count = 0;
int adjacency_matrix[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE] = {false};
queue<int> q;

void breadth_first_search(int start_vertex) {
    q.push(start_vertex);
    visited[start_vertex] = true;

    while (!q.empty()) {
        int current_vertex = q.front();
        q.pop();

        for (int i = 1; i <= num_vertices; i++) {
            if (adjacency_matrix[current_vertex][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                edge_count++;
            }
        }
    }
}

int main() {
    cin >> num_vertices >> num_edges;

    for (int i = 0; i < num_edges; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adjacency_matrix[vertex1][vertex2] = 1;
        adjacency_matrix[vertex2][vertex1] = 1; // Since it's an undirected graph
    }

    breadth_first_search(1);

    cout << edge_count;
    return 0;
}
