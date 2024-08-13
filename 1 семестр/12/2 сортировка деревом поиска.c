#include <stdio.h>
#include <stdlib.h>


typedef struct tnode{
	int node;
	struct tnode *left;
	struct tnode *right;
} tnode;


void treeprint(tnode *tree){
	if (tree != NULL){
		treeprint(tree->left);
		printf("%d\n", tree->node);
		treeprint(tree->right);
	}
}


tnode addnode(int new, tnode *tree){
	if (tree == NULL){
		tree = (tnode*) malloc(sizeof(tnode));
		tree->node = new;
		tree->left = NULL;
		tree->right = NULL;
	}
	else {
		if (new < tree->node){
			tree->left = addnode(new, tree);
		}
		else {
			tree->right = addnode(new, tree);
		}
	}
    return tree;
}


void treefree(tnode *tree){
	if (tree != NULL){
		treefree(tree->left);
		treefree(tree->right);
		free(tree);
	}
}


int main(){
	FILE *in = fopen("input.bin", "rb"), *out = fopen("output.bin", "wb");
	int n, new;
	fread(&n, sizeof(int), 1, in);

	tree = (tnode*) malloc(sizeof(tnode);
	for (int i = 0; i < n; i++){
		fread(&new, sizeof(int), 1, in);
		tree = addnode(new, tree);
	}
	
	treeprint(tree);
	treefree(tree);
	fclose(in);
	fclose(out);
	return 0;
}
