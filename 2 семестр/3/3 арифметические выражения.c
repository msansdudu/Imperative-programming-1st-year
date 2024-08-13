#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
 
typedef struct { 
    double value; 
    short type; // 1 for number, 0 for operator 
    char operator; 
} Token; 
 

double ParseExpr(char *text, int *pos); 

Token readToken(char *text, int *pos){ 
    Token token; 
    while (isspace(text[*pos])) { 
        (*pos)++; 
    } 
 
    if (text[*pos] == '\0') { 
        token.type = 1; 
        token.value = 0.0; 
    } 
    else if (text[*pos] == '+' || text[*pos] == '-' || text[*pos] == '*' || text[*pos] == '/' || text[*pos] == '(' || text[*pos] == ')') { 
        token.type = 0; 
        token.operator = text[(*pos)++]; 
    } 
    else{
        token.value = 0;
        while (text[*pos] >= '0' && text[*pos] <= '9') { 
            token.value = token.value * 10 + text[*pos] - '0';
            (*pos)++; 
        } 
        token.type = 1; 
    }
    return token; 
} 
 
Token peekToken(char *text, int *pos){ 
    int oldPos = *pos; 
    Token token = readToken(text, pos); 
    *pos = oldPos; 
    return token; 
} 
 
double ParseAtom(char *text, int *pos){ 
    Token token = peekToken(text, pos); 
    double res; 
 
    if (token.type == 0 && token.operator == '(') { 
        readToken(text, pos); 
        res = ParseExpr(text, pos); 
        readToken(text, pos); 
    }
    else { 
        res = readToken(text, pos).value; 
    } 
 
    return res; 
} 
 
 
double Elem(char *text, int *pos){ 
    double res;
    Token token = peekToken(text, pos); 
 
    if (token.type == 0 && token.operator == '-') { 
        readToken(text, pos); 
        res = 0 - ParseAtom(text, pos); 
    }
    else { 
        res = ParseAtom(text, pos); 
    } 
    return res; 
} 
 
double ParseTerm(char *text, int *pos){ 
    double res = Elem(text, pos); 
 
    while (1) { 
        Token token = peekToken(text, pos); 
 
        if (token.type == 0 && (token.operator == '*' || token.operator == '/')) { 
            char op = token.operator;
            readToken(text, pos);
            double factor = Elem(text, pos); 
            if (op == '*') {
                res *= factor; 
            }
            else { 
                res /= factor; 
            } 
        }
        else { 
            break; 
        } 
    } 
 
    return res; 
} 
 
double ParseExpr(char *text, int *pos){ 
    double res = ParseTerm(text, pos); 
 
    while (1) { 
        Token token = peekToken(text, pos); 
 
        if (token.type == 0 && (token.operator == '+' || token.operator == '-')) { 
            char op = token.operator;
            readToken(text, pos);
            double term = ParseTerm(text, pos); 
            if (op == '-') { 
                res -= term; 
            }
            else { 
                res += term; 
            } 
        }
        else { 
            break; 
        } 
    } 
 
    return res; 
} 
 
int main(){ 
    char text[500000]; 
    fgets(text, 500000, stdin);
    int pos = 0;
    printf("%.12f", ParseExpr(text, &pos));
    return 0; 
}