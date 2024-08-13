#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct List{
    char value[8];
    struct List *next;
    int id;
} List;


void push(List *p, char *data, int id){ // вставим новый узел после элемента p
    List *tmp = (List*) malloc(sizeof(List)); // выделяем новую ячейку
    strcpy(tmp->value, data); // записываем в нее нужное значение
    tmp->id = id;
    tmp->next = p->next; // записываем в tmp указатель на элемент, который был после P
    p->next = tmp; // записываем в p адрес на tmp
}


char* pop(List *p, char *val){ // удалим элемент после p, вернем его значение
    List* tmp;
    tmp = p->next;
    strcpy(val, tmp->value);
    p->next = tmp->next;
    free(tmp);
    return val;
}


void printt(List *head){ // вывод списка по порядку
	List *p;
	p = head;
	while (p->next != NULL){
		printf("%s\n", p->value);
		p = p->next;
	}
	printf("%s\n", p->value);
}


void scann(List *head, int n, int fst){ // считываем список
	int k = 0, id[100010];
	char arr[100010][8], s[8]; // массив строк
	id[0] = fst;
	for (int i = 0; i < n; i++){
		scanf("%s%d", s, &id[i + 1]);
		strcpy(arr[i], s);
	}
	
	
	strcpy(head->value, arr[id[0]]);
	head->id = id[0];
	head->next = NULL;
	k = id[k] + 1;
	List *tmp = (List*) malloc(sizeof(List));
    tmp = head;
	for (int i = 1; i < n; i++){
		push(tmp, arr[id[k]], id[k]);
		tmp = tmp->next;
		if (id[k] == -1){
			k = n;
		}
		else{
			k = id[k] + 1;
		}
	}
}


void popall(List *head){
	char val[8];
	while (head->next != NULL){
		pop(head, val);
	}
}
	
	
int main()
{
	int t, n, fst, q, op, id, nid;
	char s[8], val[8];
	scanf("%d", &t);
	List *head = (List*) malloc(sizeof(List));
	head->next = NULL;
	List *tmp;
	
	
	for (int i = 0; i < t; i++){
		popall(head);			// удалили все в списке
		scanf("%d%d%d", &n, &fst, &q);
		if (n == 0){
			strcpy(head->value, "\0");
			head->next = NULL;
			head->id = 0;
		}
		else {
			scann(head, n, fst);
		}
		nid = n - 1;
		for (int i = 0; i < q; i++){
			scanf("%d%d", &op, &id);
			if (op == 0){
				scanf("%s", s);
				nid++;
				if (id == -1){
					tmp = (List*) malloc(sizeof(List));
					strcpy(tmp->value, s);
					tmp->next = head;
					head = tmp;
					head->id = nid;
				}
				else {
					tmp = head;
					while (tmp->id != id){
						tmp = tmp->next;
					}
					push(tmp, s, nid);
				}
				printf("%d\n", nid);
			}
			else {
				if (id == 0){
					printf("%s", head->value);
					tmp = head;
					head = head->next;
					free(tmp);
				}
				else {
					tmp = head;
					while (tmp->id != id){
						tmp = tmp->next;
					}
					printf("%s\n", pop(tmp, val));
				}
			}
		}
		printf("===\n");
		printt(head);
		printf("===\n");
	}
	return 0;
}
