#include<stdio.h>
#include<stdlib.h>
#define INF 9999

void init(int n, int*** cost, int*** path);
void floyd(int n, int** cost, int** path);

int main(void) {
    int n;
    int city1, city2, weight;
    int** cost = NULL;
    int** path = NULL;
    printf("Enter the number of cities.\n");
    scanf("%d", &n);
    init(n, &cost, &path);
    
    printf("Enter the two cities and their distance(-1 -1 -1 to break, **Don't cover any route while inputing!**).\n");
    while (1) {                     /*构图*/
        scanf("%d%d%d", &city1, &city2, &weight); 
        if (city1 == -1 && city2 == -1 && weight == -1) { 
            break;            /*输入-1停止*/
        }
        cost[city1][city2] = weight;        /*从行出发，到列，下标起于0*/
        path[city1][city2] = city1;
        cost[city2][city1] = weight;
        path[city2][city1] = city2;
    }
    
    floyd(n, cost, path);

    while (1) {
        printf("Enter the cities to find the shortest path(-1 -1 to break).\n");
        scanf("%d%d", &city1, &city2);
        if (city1 == -1 && city2 == -1) {
            break;
        }
        if (cost[city1][city2] == INF) {
            printf("No such route.\n");
            continue;
        }
        printf("cost = %d\n", cost[city1][city2]);
        printf("%d->", city1);
        while (path[city2][city1] >= 0) {
            printf("%d->", path[city2][city1]);
            city1 = path[city2][city1];
        }
        printf("\b\b  \b\b\n");
    }

    return 0;
}

void init(int n, int*** cost, int*** path) {
    int i, j;
    (*cost) = (int**)malloc(sizeof(int*)*n);
    if ((*cost) == NULL) {
        printf("Out of Memory!!!\n");
        system("pause");
        exit(1);
    }
    (*path) = (int**)malloc(sizeof(int*)*n);
    if ((*path) == NULL) {
        printf("Out of Memory!!!\n");
        system("pause");
        exit(1);
    }
    for (i = 0; i < n; ++i) {
        (*cost)[i] = (int*)malloc(sizeof(int)*n);
        if ((*cost)[i] == NULL) {
            printf("Out of Memory!!!\n");
            system("pause");
            exit(1);
        }
        (*path)[i] = (int*)malloc(sizeof(int)*n);
        if ((*path)[i] == NULL) {
            printf("Out of Memory!!!\n");
            system("pause");
            exit(1);
        }
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            (*cost)[i][j] = INF;
            (*path)[i][j] = -1;
            if (i == j) {
                (*cost)[i][j] = 0;
            }
        }
    }
}

void floyd(int n, int** cost, int** path) {
    int i, j, k;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                if ((cost[j][k] > cost[j][i] + cost[i][k])) {
                    cost[j][k] = cost[j][i] + cost[i][k];
                    path[j][k] = path[i][k];
                }
            }
        }
    }
}


