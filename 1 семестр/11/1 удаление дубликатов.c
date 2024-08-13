#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
	int key;
	struct Node *next;
} Node;


uint32_t jenkins(const uint8_t* key, size_t len) {
	int32_t hash = 0;
	for (size_t i = 0; i < len; i++) {
		hash += key[i];
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
    return hash;
}


int check(Node **hashTable, int elem, int TABLE_SIZE) {
	int key = jenkins((uint8_t*) (&elem), sizeof(int)) % TABLE_SIZE;
	Node *curr = hashTable[key], *prev = NULL;
	while (curr != NULL && curr->key != elem) {
		prev = curr;
		curr = curr->next;
	}
	if (curr != NULL) {
		return 0;
	}
		
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->key = elem;
	newNode->next = NULL;
	if (prev != NULL){
		prev->next = newNode;
	}
	else {
		hashTable[key] = newNode;
	}
	return 1;
}


int main(){
	FILE *in = fopen("input.bin", "rb"), *out = fopen("output.bin", "wb");
    int n, elem, *new_arr, new_size = 0;
	
    fread(&n, sizeof(int), 1, in);
    int TABLE_SIZE = n;
    Node **hashTable = (Node**) malloc(TABLE_SIZE * sizeof(Node*));
    for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
    new_arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
		fread(&elem, sizeof(int), 1, in);
		if (check(hashTable, elem, TABLE_SIZE)){
			new_arr[new_size++] = elem;
		}
	}

	fwrite(&new_size, sizeof(int), 1, out);
	fwrite(new_arr, sizeof(int), new_size, out);
	free(new_arr);
	fclose(in);
	fclose(out);
    return 0;
}

