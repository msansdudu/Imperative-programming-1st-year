#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct list_without_doubles
{
  struct list_without_doubles* next;
  int element;
} list;

uint32_t jenkins(const uint8_t* key, size_t len)
{
  uint32_t result_hash = 0;
  for (size_t i = 0; i < len; i++)
  {
    result_hash += key[i];
    result_hash += result_hash << 10;
    result_hash ^= result_hash >> 6;
  }
  result_hash += result_hash << 3;
  result_hash ^= result_hash >> 11;
  result_hash += result_hash << 15;
  return result_hash;
}

int add_new_element(int el, list** table, int size_of_hash_table)
{

  list** pntr = 0;
  uint8_t* new_pointerr = (uint8_t*)(&el);
  int current_hash = jenkins(new_pointerr, sizeof(int)) % size_of_hash_table;

  for (pntr = &(table[current_hash]); *pntr != NULL; pntr = &((*pntr)->next))
  {
    if ((*pntr)->element == el)
    {
      return 0;
    }
  }

  (*pntr) = (list*)malloc(sizeof(list));
  (*pntr)->element = el;
  (*pntr)->next = NULL;

  return 1;

}

int main() {

  freopen("input.bin", "rb", stdin);
  freopen("output.bin", "wb", stdout);

  int n = 0;
  fread(&n, 4, 1, stdin);
  list** listt = (list**)malloc(n * sizeof(list*));
  int* m = (int*)malloc(n * sizeof(int));
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    listt[i] = NULL;
  }

  int new_element = 0;
  for (int i = 0; i < n; i++)
  {
    fread(&new_element, 4, 1, stdin);
    int result = add_new_element(new_element, listt, n);
    if (result == 1)
    {
      m[count] = new_element;
      count++;
    }
  }

  fwrite(&count, 4, 1, stdout);
  fwrite(m, 4, count, stdout);

  free(listt);
  return 0;

}
