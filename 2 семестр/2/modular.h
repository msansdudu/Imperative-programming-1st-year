#ifndef MODULAR_H_
#define MODULAR_H_
int MOD;
int pnorm(int a);
int padd(int a, int b);
int psub(int a, int b);
int pmul(int a, int b);
void ext_euclid(long long a, long long b, long long *x, long long *y, long long *d);
long long inverse(long long a, long long m);
int pdiv(int a, int b);
#endif
