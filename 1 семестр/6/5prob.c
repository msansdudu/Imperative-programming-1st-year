#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t{
    char str[9];
    struct node_t* next;
} node;

void insert_node(node** head,node** tail, char* str){
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->str, str);
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
        *tail = new_node;
        return;
    }
    node* current = *tail;
    current->next = new_node;
    *tail = current->next;
}

int main(){
    int n;
    scanf("%d", &n);
    node* records[1000001] = {NULL};
    node* tail[1000001]= {NULL};
    for(int i=0; i<n; i++){
        int key;
        char value[9];
        scanf("%d %s", &key, value);
        insert_node(&records[key],&tail[key], value);
    }

    for(int i=0; i<1000001; i++){
        node* current = records[i];
        while(current != NULL){
            printf("%d %s\n", i, current->str);
            node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
