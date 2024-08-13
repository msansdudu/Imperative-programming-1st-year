#ifndef MODULAR_H_
#define MODULAR_H_
typedef struct IntegerSet{
	int *arr;			//сам список чисел
	int n;				//количество чисел
} IntegerSet;
IntegerSet *CreateSet(int *arr, int n); //принимает массив и количество чисел в массиве
void DeleteSet(IntegerSet *set);		//принимает указатель на интеджерсет, который надо удалить
int IsInSet(IntegerSet *set, int n); 	//принимает указатель на интеджерсет и число на проверку
#endif
