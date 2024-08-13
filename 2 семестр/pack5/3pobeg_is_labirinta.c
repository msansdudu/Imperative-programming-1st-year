#include <stdio.h>
#include <stdlib.h>

int m, n, queue[10010][2], dist[110][110];
char lab[110][110];



void bfs(int cur_i, int cur_j){
    int front = 0, rear = 0, i, j;
    queue[rear][0] = cur_i;
    queue[rear][1] = cur_j;
    rear++;
    while (front <= rear){
        cur_i = queue[front][0];
        cur_j = queue[front][1];
        front++;
        i = cur_i + 1;
        j = cur_j;
        if (lab[i][j] != 'X' && i >= 0 && j >= 0 && i < m && j < n && dist[i][j] == -1){
            queue[rear][0] = i;
            queue[rear][1] = j;
            rear++;
            dist[i][j] = dist[cur_i][cur_j] + 1;
        }
        i = cur_i - 1;
        j = cur_j;
        if (lab[i][j] != 'X' && i >= 0 && j >= 0 && i < m && j < n && dist[i][j] == -1){
            queue[rear][0] = i;
            queue[rear][1] = j;
            rear++;
            dist[i][j] = dist[cur_i][cur_j] + 1;
        }
        i = cur_i;
        j = cur_j + 1;
        if (lab[i][j] != 'X' && i >= 0 && j >= 0 && i < m && j < n && dist[i][j] == -1){
            queue[rear][0] = i;
            queue[rear][1] = j;
            rear++;
            dist[i][j] = dist[cur_i][cur_j] + 1;
        }
        i = cur_i;
        j = cur_j - 1;
        if (lab[i][j] != 'X' && i >= 0 && j >= 0 && i < m && j < n && dist[i][j] == -1){
            queue[rear][0] = i;
            queue[rear][1] = j;
            rear++;
            dist[i][j] = dist[cur_i][cur_j] + 1;
        }
    }
}

int main(){
    int in_i, in_j, out_i, out_j;
    scanf("%d %d\n", &m, &n);
    for (int i = 0; i < m; i++){
        gets(lab[i]);
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (lab[i][j] == 'S'){
                in_i = i;
                in_j = j;
            }
            if (lab[i][j] == 'F'){
                out_i = i;
                out_j = j;
            }
            dist[i][j] = -1;
        }
    }
    dist[in_i][in_j] = 0;

    bfs(in_i, in_j);
    printf("%d", dist[out_i][out_j]);
    return 0;
}