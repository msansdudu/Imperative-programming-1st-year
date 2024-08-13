#include <stdio.h>
#include <stdlib.h>

char lab[1010][1010];

void obhod(int n, int i, int j){
    if (i < 0 || j < 0 || j >= n || i >= n || lab[i][j] != ' '){
        return;
    }
    lab[i][j] = 1;
    obhod(n, i + 1, j);
    obhod(n, i - 1, j);
    obhod(n, i, j + 1);
    obhod(n, i, j - 1);
}


int main(){
    int n, ent = 0;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++){
        gets(lab[i]);
    }
    for (int j = 0; j < n; j++){
        if (lab[0][j] == ' '){
            ent = j;
            break;
        }
    }

    obhod(n, 0, ent);

    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (lab[i][j] == ' '){
                count++;
                obhod(n, i, j);
            }
        }
    }
    printf("%d", count);
    return 0;
}