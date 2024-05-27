#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[501][501];
int visited[501];
int cnt[501];

void dfs(int n, int now, int start);
void inverse_dfs(int n, int now, int start);
void resetVisited(int n);
void inputGraph(int& n, int& m);
void processNodes(int n);
int countTotal(int n);

void dfs(int n, int now, int start){
    if(visited[now] == 0)
        cnt[start]++;
    visited[now] = 1;
    
    for(int i=1; i<=n; i++){
        if(map[now][i]==1 && visited[i] == 0){
            dfs(n, i, start);
        }
    }
}

void inverse_dfs(int n, int now, int start){
    if(visited[now] == 0)
        cnt[start]++;
    visited[now] = 1;
    
    for(int i=1; i<=n; i++){
        if(map[now][i]==-1 && visited[i] == 0){
            inverse_dfs(n, i, start);
        }
    }
}

void resetVisited(int n){
    fill(visited, visited + n + 1, 0);
}

void inputGraph(int& n, int& m){
    scanf("%d %d", &n, &m);
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = -1;
    }
}

void processNodes(int n){
    for(int i = 1; i <= n; i++){
        dfs(n, i, i);
        resetVisited(n);
        inverse_dfs(n, i, i);
        resetVisited(n);
    }
}

int countTotal(int n){
    int total = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == n + 1){
            total++;
        }
    }
    return total;
}

int main(){
    int n, m;
    inputGraph(n, m);
    processNodes(n);
    int total = countTotal(n);
    printf("%d\n", total);
    return 0;
}