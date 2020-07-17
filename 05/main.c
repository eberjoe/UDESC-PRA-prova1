#include <stdio.h>
#include <stdlib.h>

int main() {
    int luva, *listaDeLuvas = NULL, *idTamanhoRepetido = NULL, c = 0, i, j, k, r, pares = 0;
    do {
    printf("Entre um tamanho de luva ou 0 para terminar: ");
        if (scanf("%d", &luva) && luva > 0) {
            listaDeLuvas = realloc(listaDeLuvas, sizeof(int) * (c + 1));
            listaDeLuvas[c] = luva;
            c++;
        } else {
            break;
        }
    } while (1);
        if (c > 1) {
            for (i = 0; i < c - 1; i++) {
                if (listaDeLuvas[i]) {
                    r = 1;
                    for (j = i + 1; j < c; j++) {
                        if (listaDeLuvas[j] == listaDeLuvas[i]) {
                            r++;
                            idTamanhoRepetido = realloc(idTamanhoRepetido, sizeof(int) * r);
                            idTamanhoRepetido[r - 1] = j;
                        }
                    }
                    if (r > 1) {
                        idTamanhoRepetido[0] = i;
                        pares += r / 2;
                        for (k = 0; k < r; k++) {
                            listaDeLuvas[idTamanhoRepetido[k]] = 0;
                        }
                    }
                }
            }
            printf("\nNúmero de pares: %d\n", pares);
        }
    printf("\nFIM\n");
    free(listaDeLuvas);
    free(idTamanhoRepetido);
    return 1;
}