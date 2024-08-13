#include <stdio.h>
#include "myblas.h"

//скопировать вектор из X в Y
void dcopy(int n, const double *X, double *Y){
	for (int i = 0; i < n; i++){
		Y[i] = X[i];
	}
}

//обменять местами содержимое векторов X и Y
void dswap(int n, double *X, double *Y){
	double tmp;
	for (int i = 0; i < n; i++){
		tmp = Y[i];
		Y[i] = X[i];
		X[i] = tmp;
	}
}

//домножить вектор X на коэффициент alpha
void dscal(int n, double alpha, double *X){
	for (int i = 0; i < n; i++){
		X[i] *= alpha;
	}
}


//прибавить к вектору Y вектор X, умноженный на коэффициент alpha
void daxpy(int n, double alpha, const double *X, double *Y){
	for (int i = 0; i < n; i++){
		Y[i] += X[i] * alpha;
	}
}

//вычислить скалярное произведение векторов X и Y
double ddot(int n, const double *X, const double *Y){
	double res = 0;
	for (int i = 0; i < n; i++){
		res += Y[i] * X[i];
	}
	return res;
}
