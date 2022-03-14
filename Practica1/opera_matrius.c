#include <stdio.h>

#define A_F 10
#define A_C 3
#define B_F 3
#define B_C 15




void main() {
    FILE *f_A = fopen("valors_A.txt", "r");
    FILE* f_B = fopen("valors_B.txt", "r");

    if(f_A == NULL) {
        perror ("Error a l'obrir valors_A.txt");
    }

    if(f_B == NULL) {
        perror ("Error a l'obrir valors_B.txt");
    }

    int matriu_A[A_F][A_C];
    int matriu_B[B_F][B_C];
      
    //COPIAR MATRIU DEL TXT
    int n = 0;

    for (int i = 0; i < A_F; i++) {
        for (int j = 0; j < A_C; j++) {
            fscanf(f_A, "%i", &n);
            matriu_A[i][j] = n;
        }
    }
    fclose(f_A);

    //MATRIU TRASPOSTA

    int matriu_AT[A_C][A_F];

    for (int i = 0; i < A_F; i++) {
        for (int j = 0; j < A_C; j++) {
            matriu_AT[i][j] = matriu_A[j][i];
        }
    }


    //IMPRIMIR MATRIU PER PANTALLA
    for (int i = 0; i < A_F; i++) {
        for (int j = 0; j < A_C; j++) {
            printf("%i ", matriu_AT[i][j]);
        }
        printf("\n");
    }

}