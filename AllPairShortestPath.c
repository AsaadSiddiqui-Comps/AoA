#include <stdio.h>

#define MAX 100
#define INF 1000000000

void initGraph(int n, int dist[MAX][MAX]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

void addEdge(int u, int v, int w, int dist[MAX][MAX]) {
    dist[u][v] = w;
}

void floydWarshall(int n, int dist[MAX][MAX]) {
    int k, i, j;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    int through_k = dist[i][k] + dist[k][j];
                    if (through_k < dist[i][j])
                        dist[i][j] = through_k;
                }
            }
        }
    }
}

void printMatrix(int n, int dist[MAX][MAX]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] >= INF/2)
                printf("INF");
            else
                printf("%d", dist[i][j]);
            if (j + 1 < n) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        printf("Invalid input\n");
        return 1;
    }
    if (n <= 0 || n > MAX) {
        printf("n must be between 1 and %d\n", MAX);
        return 1;
    }

    int dist[MAX][MAX];
    initGraph(n, dist);

    int i;
    for (i = 0; i < m; i++) {
        int u, v, w;
        if (scanf("%d %d %d", &u, &v, &w) != 3) {
            printf("Invalid edge input\n");
            return 1;
        }
        if (u < 1 || u > n || v < 1 || v > n) {
            printf("Node indices must be in 1..%d\n", n);
            return 1;
        }
        addEdge(u - 1, v - 1, w, dist);
    }

    floydWarshall(n, dist);

    printMatrix(n, dist);
    return 0;
}
