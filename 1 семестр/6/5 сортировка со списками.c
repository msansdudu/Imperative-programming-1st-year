#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List{
	char value[8];
	struct List *next;
} List;


void new(List **head, List **last, char *s){
	List *tmp = (List*) malloc(sizeof(List));
	strcpy(tmp->value, s);
	tmp->next = NULL;
	if (*head == NULL){
		*head = tmp;
		*last = *head;
	}
	else {
		(*last)->next = tmp;
		*last = tmp;
	}
}


int main()
{
	int key, n;
	List *arr[1000010] = {NULL}, *last[1000010] = {NULL}, *p, *tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		tmp = (List*) malloc(sizeof(List));
		scanf("%d%s", &key, tmp->value);
		tmp->next = NULL;
		if (arr[key] == NULL){
			arr[key] = tmp;
			last[key] = tmp;
		}
		else {
			last[key]->next = tmp;
			last[key] = tmp;
		}
	}
	
	for (int i = 0; i < 1000010; i++){
		p = arr[i];
		while (p != NULL){
			printf("%d %s\n", i, p->value);
			p = p->next;
		}
	}
	return 0;
}

