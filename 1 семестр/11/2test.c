#include <stdio.h>
#include <stdlib.h>

typedef struct listt {
    struct listt* next;
    int element;
} list;

list* add_element(list* lst, int new) {

    list* new_element = (list*)malloc(sizeof(list));

    new_element->next = lst;
    new_element->element = new;

    return new_element;
    
}

void sum_of_even(void* context, int* value_odd_or_even) {

    if ((*value_odd_or_even) % 2 == 0)
    {
        *((int*)context) += (*value_odd_or_even);
    }

}

typedef void (*callback)(void* ctx, int* value);

void arrayForeach(void* ctx, callback func, int* arr, int n) {

    for (int i = 0; i < n; i++)
    {
        func(ctx, &(arr[i]));
    }

}

void listForeach(void* ctx, callback func, list* lst) {

    for (list* i = lst; i != NULL; i = i->next)
    {
        func(ctx, &(i->element));
    }

}

int main() {

    int n = 0;
    scanf("%d", &n);

    int* m = (int*)malloc(n * sizeof(int));

    list* first_of_list = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
        first_of_list = add_element(first_of_list, m[i]);
    }

    int sum_for_array = 0;
    int sum_for_list = 0;

    arrayForeach((&sum_for_array), sum_of_even, m, n);
    listForeach((&sum_for_list), sum_of_even, first_of_list);

    printf("%d %d", sum_for_array, sum_for_list);

    return 0;

}
