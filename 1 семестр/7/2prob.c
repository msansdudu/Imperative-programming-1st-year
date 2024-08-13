#include <stdio.h> 
#include <stdint.h> 
 
typedef uint64_t bitword; 
bitword arr[312501]; 
 
// инициализация массива 
void bitsetZero(bitword *arr, int num) 
{ 
    for (int i = 0; i <= (num / 64); i++) 
    { 
        arr[i] = (arr[i] & (~arr[i])); 
    } 
} 
 
// поменять значение бита 
void bitsetSet(bitword *arr, int idx, int newval) 
{ 
    if (newval == 1) 
    { 
        arr[idx / 64] |= ((bitword)1 << (idx % 64)); // присвоить 1 биту 
    } 
    else 
    { 
        arr[idx / 64] &= ~((bitword)1 << (idx % 64)); // занулить бит 
    } 
} 
 
// получить значение бита 
int bitsetGet(const bitword *arr, int idx) 
{ 
    return ((arr[idx / 64] >> (idx % 64)) & (bitword)1); // сдвигает вправо и только крайний бит справа единичика, осталбные нуди 
} 
 
// есть ли единичный 
int bitsetAny(const bitword *arr, int left, int right) 
{ 
    int curr = left / 64; 
    if (right - left < 64) 
    { 
        for (int i = left; i < right; i++) 
        { 
            if (i % 64 == 0 && i != left) 
            { 
                curr++; 
            } 
            if ((arr[curr] >> (i % 64)) & 1) 
            { 
                return 1; 
            } 
        } 
        return 0; 
    } 
    if (left % 64 != 0) 
    { 
        for (int i = left; i < (left / 64 + 1) * 64; i++) 
        { 
            if ((arr[curr] >> (i % 64)) & 1) 
            { 
                return 1; 
            } 
        } 
        left = (left / 64 + 1) * 64; 
        curr++; 
    } 
    for (int i = left / 64; i < right / 64; i++) 
    { 
        if (arr[i]) 
        { 
            return 1; 
        } 
        curr++; 
    } 
    if (right % 64 != 0) 
    { 
        for (int i = right / 64 * 64; i < right; i++) 
        { 
            if ((arr[curr]) >> (i % 64) & 1) 
            { 
                return 1; 
            } 
        } 
    } 
    return 0; 
} 
 
int main() 
{ 
    int n; 
    int operation; 
    int num; 
    int bitIndex; 
    int bitValue; 
    int left, right; 
    int result1, result2; 
 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
 
    scanf("%d", &n); 
 
    for (int i = 0; i < n; i++) 
    { 
        scanf("%d", &operation); 
 
        if (operation == 0) 
        { 
            scanf("%d", &num); 
            bitsetZero(arr, num); 
        } 
 
        if (operation == 2) 
        { 
            scanf("%d %d", &bitIndex, &bitValue); 
            bitsetSet(arr, bitIndex, bitValue); 
        } 
 
        if (operation == 1) 
        { 
            scanf("%d", &bitIndex); 
            result2 = bitsetGet(arr, bitIndex); 
            printf("%d\n", result2); 
        } 
 
        if (operation == 3) 
        { 
            scanf("%d %d", &left, &right); 
            result1 = bitsetAny(arr, left, right); 
            if (result1 == 0) 
            { 
                printf("none\n"); 
            } 
            else 
            { 
                printf("some\n"); 
            } 
        } 
    } 
 
    fclose(stdin); 
    fclose(stdout); 
    return 0; 
}
