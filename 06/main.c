#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

// Não funciona com acentuação porque restrito a ASCII

int lev(int x, int y, char* s1, char* s2);

int main() {
    char str1[MAX], str2[MAX];
    int t1, t2, i, j, distancia;
    printf("Entre a primeira string: ");
    fgets(str1, MAX, stdin);
    printf("Entre a segunda string: ");
    fgets(str2, MAX, stdin);
    t1 = strlen(str1);
    t2 = strlen(str2);
    for (i = t1 - 1; i; i--)
        str1[i] = str1[i - 1];
    for (i = t2 - 1; i; i--)
        str2[i] = str2[i - 1];
    printf("%s\n", str1);
    printf("%s\n", str2);
    for (i = 0; i < t2; i++) {
        for (j = 0; j < t1; j++) {
            distancia = lev(j, i, str1, str2);
            printf("%d\t", distancia);
        }
        printf("\n");
    }
    printf("\nA distância de Levenshtein é %d\n", distancia);
    return 1;
}

int lev(int x, int y, char* s1, char* s2) {
    int a, b, c;
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    a = lev(x - 1, y, s1, s2) + 1;
    b = lev(x, y - 1, s1, s2) + 1;
    c = lev(x - 1, y - 1, s1, s2);
    c += (s1[x] != s2[y]);
    if (a < b && a < c)
        return a;
    else if (b < c)
        return b;
    return c;
}