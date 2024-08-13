#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;


typedef void (*callback)(void *ctx, int *value);


void only_even(void *ctx, int *elem){
	if ((*elem) % 2 == 0){
		*((int*) ctx) += (*elem);
	}
}


void arrayForeach(void *ctx, callback func, int *arr, int n){
	for (int i = 0; i < n; i++){
		func(ctx, &(arr[i]));
	}
}


void listForeach(void *ctx, callback func, Node *first) {
	for (Node* curr = first; curr != NULL; curr = curr->next){
		func(ctx, &(curr->value));
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	int *arr = (int*) malloc(n * sizeof(int));
	Node *first = NULL;
	
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		Node *new_node = (Node*) malloc(sizeof(Node));
		new_node->next = first;
		new_node->value = arr[i];
		first = new_node;
	}
	
	int a = 0, b = 0;
	arrayForeach(&a, only_even, arr, n);
	listForeach(&b, only_even, first);
	printf("%d %d", a, b);
	return 0;
}

