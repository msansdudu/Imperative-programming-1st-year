#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct State {
    char *regs[256];
} State;

void echo_0(State *state){
    printf("ECHO: \n");
}
void echo_1(State *state, char *arg0){
    printf("ECHO: %s\n", arg0);
}
void echo_2(State *state, char *arg0, char *arg1){
    printf("ECHO: %s|%s\n", arg0, arg1);
}
void echo_3(State *state, char *arg0, char *arg1, char *arg2){
    printf("ECHO: %s|%s|%s\n", arg0, arg1, arg2);
}

//prints contents of I-th register (it must not be NULL)
//[idx] contains decimal representation of I
void print_1(State *state, char *idx){
    printf("%s\n", state->regs[atoi(idx)]);
}

void printregs_0(State *state){
    for (int i = 0; i < 256; i++){
        if (state->regs[i] != NULL){
            printf("%d = %s\n", i, state->regs[i]);
        }
    }
}

void store_2(State *state, char *idx, char *what){
    int id = atoi(idx);
    int len = strlen(what);
    state->regs[id] = (char*) malloc((len + 1) * sizeof(char));
    strcpy(state->regs[id], what);
    (state->regs[id])[len] = '\0';
}

void copy_2(State *state, char *dst, char *src){
    int id_to = atoi(dst);
    int id_from = atoi(src);
    int len = strlen(state->regs[id_from]);
    state->regs[id_to] = (char*) malloc((len + 1) * sizeof(char));
    strcpy(state->regs[id_to], state->regs[id_from]);
    (state->regs[id_to])[len] = '\0';
}

void clear_1(State *state, char *idx){
    int id = atoi(idx);
    free(state->regs[id]);
    state->regs[id] = NULL;
}

State state ;
int main(){
for (int i = 0; i < 256; i++){
    state.regs[i] = NULL;
}
echo_2 (& state , "hello", "world");
echo_0 (& state );
echo_1 (& state , "the_only_argument");
echo_3 (& state , "a", "b", "c");
store_2 (& state , "13", "thirteen");
store_2 (& state , "10", "ten");
store_2 (& state , "15", "fifteen");
store_2 (& state , "20", "twelve");
echo_1 (& state , "== state ==");
printregs_0 (& state );
echo_1 (& state , "== copying ==");
print_1 (& state , "13");
print_1 (& state , "15");
copy_2 (& state , "13", "15");
print_1 (& state , "13");
print_1 (& state , "15");
echo_1 (& state , "== clear ==");
clear_1 (& state , "10");
clear_1 (& state , "15");
store_2 (& state , "13", "thirteen_V2");
printregs_0 (& state );
}