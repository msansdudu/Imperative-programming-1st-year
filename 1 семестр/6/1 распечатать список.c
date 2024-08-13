#include <stdio.h>
#include <stdlib.h>


typedef struct List{
    double value;
    struct List *next;
} List;


void push(List *p, double data){ // вставим новый узел после элемента p
    List *tmp = (List*) malloc(sizeof(List)); // выделяем новую ячейку
    tmp->value = data; // записываем в нее нужное значение
    tmp->next = p->next; // записываем в tmp указатель на элемент, который был после P
    p->next = tmp; // записываем в p адрес на tmp
}


void printt(List *head){ //вывод списка по порядку
	List *p;
	p = head;
	while (p->next != NULL){
		printf("%0.3lf\n", p->value);
		p = p->next;
	}
	printf("%0.3lf\n", p->value);
}


int main()
{
	int n, k = 0, id[100001];
	double arr[100000];
	scanf("%d%d", &n, &id[0]);
	for (int i = 0; i < n; i++){
		scanf("%lf%d", &arr[i], &id[i + 1]);
	}
	
	List *head = (List*) malloc(sizeof(List));
	head->value = arr[id[0]];
	head->next = NULL;
	k = id[k] + 1;
	List *tmp = (List*) malloc(sizeof(List));
    tmp = head;
	
	
	for (int i = 1; i < n; i++){
		push(tmp, arr[id[k]]);
		tmp = tmp->next;
		if (id[k] == -1){
			k = n;
		}
		else{
			k = id[k] + 1;
		}
	}
	
	printt(head);
	return 0;
}
