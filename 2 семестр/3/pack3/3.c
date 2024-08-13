#include <stdio.h> 
#include <ctype.h> 
#include <stdlib.h> 
 
#define MAX_SIZE 500000 
 
typedef struct { 
    short type; // 1 for number, 0 for operator 
    double value; 
    char operator; 
} Token; 
 
Token readToken(char text[], int *pos) { 
    Token token; 
    int left = *pos; 
 
    while (isspace(text[*pos])) { 
        (*pos)++; 
    } 
 
    if (text[*pos] == '\0') { 
        token.type = 'n'; 
        token.value = 0.0; 
        return token; 
    } 
 
    if (text[*pos] == '+' || text[*pos] == '-' || text[*pos] == '*' || text[*pos] == '/') { 
        token.type = 'o'; 
        token.operator = text[(*pos)++]; 
        return token; 
    } 
 
    if (text[*pos] == '(' || text[*pos] == ')') { 
        token.type = 'o'; 
        token.operator = text[(*pos)++]; 
        return token; 
    } 
 
    if (text[*pos] == '-' && (*pos == 0 || text[*pos - 1] == '(' || !isdigit(text[*pos - 1]))) { 
        token.type = 'o'; 
        token.operator = '-'; 
        (*pos)++; 
        return token; 
    } 
 
    while (text[*pos] >= '0' && text[*pos] <= '9') { 
        (*pos)++; 
    } 
 
    char temp[500000]; 
    for (int i = left; i < *pos; i++) { 
        temp[i - left] = text[i]; 
    } 
    temp[*pos - left] = '\0'; 
    token.type = 'n'; 
    token.value = strtod(temp, NULL); 
 
    return token; 
} 
 
Token peekToken(char text[], int *pos) { 
    int oldPos = *pos; 
    Token token = readToken(text, pos); 
    *pos = oldPos; 
    return token; 
} 
 
double ParseExpr(char text[], int *pos); 
 
double ParseAtom(char text[], int *pos) { 
    Token token = peekToken(text, pos); 
    double res; 
 
    if (token.type == 'o' && token.operator == '(') { 
        readToken(text, pos); 
        res = ParseExpr(text, pos); 
        Token closeBracket = readToken(text, pos); 
 
        if (closeBracket.type != 'o' || closeBracket.operator != ')') { 
            printf("Error: Missing closing bracket\n"); 
            exit(1); 
        } 
    } else { 
        res = readToken(text, pos).value; 
    } 
 
    return res; 
} 
 
 
double ParseFactor(char text[], int *pos) { 
    double res; 
    Token token = peekToken(text, pos); 
 
    if (token.type == 'o' && token.operator == '-') { 
        readToken(text, pos); 
        res = 0 - ParseAtom(text, pos); 
    } else { 
        res = ParseAtom(text, pos); 
    } 
 
    return res; 
} 
 
double ParseTerm(char text[], int *pos) { 
    double res = ParseFactor(text, pos); 
 
    while (1) { 
        Token nextToken = peekToken(text, pos); 
 
        if (nextToken.type == 'o' && (nextToken.operator == '*' || nextToken.operator == '/')) { 
            char oper = readToken(text, pos).operator; 
            double factor = ParseFactor(text, pos); 
 
            if (oper == '*') { 
                res *= factor; 
            } else { 
                res /= factor; 
            } 
        } else { 
            break; 
        } 
    } 
 
    return res; 
} 
 
double ParseExpr(char text[], int *pos) { 
    double res = ParseTerm(text, pos); 
 
    while (1) { 
        Token nextToken = peekToken(text, pos); 
 
        if (nextToken.type == 'o' && (nextToken.operator == '+' || nextToken.operator == '-')) { 
            char oper = readToken(text, pos).operator; 
            double term = ParseTerm(text, pos); 
 
            if (oper == '+') { 
                res += term; 
            } else { 
                res -= term; 
            } 
        } else { 
            break; 
        } 
    } 
 
    return res; 
} 
 
int main() { 
    char text[MAX_SIZE]; 
    int pos = 0; 
 
    fgets(text, MAX_SIZE, stdin); 
 
    double result = ParseExpr(text, &pos); 
 
    printf("%.12f\n", result); 
 
    return 0; 
}