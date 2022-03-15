#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* A= "valors_A.txt";
char* B= "valors_B.txt";
const char* C= "traza_opera_matrius.prg";


//llegir A

void llegirA(FILE *file, FILE *fileW, int mat[10][3]){
    int num;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            fscanf(file, "%i", &num);
            mat[i][j] = num;
            fprintf(fileW, "%d %p\n", 3, &mat[i][j]);
        }
    }
}

//llegir B

void llegirB(FILE *file, FILE *fileW, int mat[3][15]){
    int num;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 15; j++){
            fscanf(file, "%i", &num);
            mat[i][j] = num;
            fprintf(fileW, "%d %p\n", 3, &mat[i][j]);
        }
    }
}

//trasposar A

void traspassA(FILE *file, int matA[10][3], int matAt[3][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            matAt[i][j] = matA[j][i];
            fprintf(file, "%d %p\n", 2, &matA[j][i]);
            fprintf(file, "%d %p\n", 3, &matAt[i][j]);
        }
    }
}

//trasposar B

void traspassB(FILE *file, int matB[3][15], int matBt[15][3]){
    for(int i = 0; i< 15; i++){
        for(int j = 0; j< 3; j++){
            matBt[i][j] = matB[j][i];
            fprintf(file, "%d %p\n", 2, &matB[j][i]);
            fprintf(file, "%d %p\n", 3, &matBt[i][j]);
        }
    }
}

//multiplicar A*B

void multiplyAB(FILE *file, int matA[10][3], int matB[3][15], int matAB[10][15]){
    int sum = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 15; j++){
                for(int k = 0; k < 3; k++){
                     sum += matA[i][k] * matB[k][j]; 
                     fprintf(file, "%d %p\n", 2, &matA[i][k]);
                     fprintf(file, "%d %p\n", 2, &matB[k][j]);
                }
                matAB[i][j]= sum;
                fprintf(file, "%d %p\n", 3, &matAB[i][j]);
                sum = 0;
            }
        }
}

//trasposar A*B

void traspassAB(FILE *file, int matAB[10][15], int matABt[15][10]){
    for(int i = 0; i< 15; i++){
        for(int j = 0; j< 10; j++){
            matABt[i][j] = matAB[j][i];
            fprintf(file, "%d %p\n", 2, &matAB[j][i]);
            fprintf(file, "%d %p\n", 3, &matABt[i][j]);
        }
    }
}

//multiplicar les trasposades

void multiplyBtAt(FILE *file, int matBt[15][3], int matAt[3][10], int matBtAt[15][10]){
    int sum = 0;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 3; k++){
                sum += matBt[i][k] * matAt[k][j]; 
                fprintf(file, "%d %p\n", 2, &matBt[i][k]);
                fprintf(file, "%d %p\n", 2, &matAt[k][j]);
            }
            matBtAt[i][j]= sum;
            fprintf(file, "%d %p\n", 3, &matBtAt[i][j]);
            sum = 0;
        }
    }
}

//comprovar la propietat

bool compare(FILE *file, int matABt[15][10], int matBtAt[15][10]){
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 10; j++) {
            if(matABt[i][j] != matBtAt[i][j]) return false;
            fprintf(file, "%d %p\n", 2, &matABt[i][j]);
            fprintf(file, "%d %p\n", 2, &matBtAt[i][j]);
        }
    }
    return true;
}

//negar matrius

void negateA(FILE *file, int matA[10][3], int matAn[10][3]){
    for(int i = 0; i< 10; i++){
        for(int j = 0; j< 3; j++){
            matAn[i][j] = -matA[i][j];
            fprintf(file, "%d %p\n", 2, &matA[i][j]);
            fprintf(file, "%d %p\n", 3, &matAn[i][j]);
        }
    }
}


void negateB(FILE *file, int matB[3][15], int matBn[3][15]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 15; j++){
            matBn[i][j] = -matB[i][j];
            fprintf(file, "%d %p\n", 2, &matB[i][j]);
            fprintf(file, "%d %p\n", 3, &matBn[i][j]);
        }
    }
}

//funcions per a imprimir les matrius

void printAAn(FILE *file, int mat[10][3]){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%i ", mat[i][j]);
            fprintf(file, "%d %p\n", 2, &mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printAt(FILE *file, int mat[3][10]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%i ", mat[i][j]);
            fprintf(file, "%d %p\n", 2, &mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printBBn(FILE *file, int mat[3][15]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 15; j++) {
            printf("%i ", mat[i][j]);
            fprintf(file, "%d %p\n", 2, &mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printBt(FILE *file, int mat[15][3]){
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%i ", mat[i][j]);
            fprintf(file, "%d %p\n", 2, &mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printPropietat(FILE *file, int mat[15][10]){
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%i ", mat[i][j]);
            fprintf(file, "%d %p\n", 2, &mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printAB(FILE *file, int mat[10][15]){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            printf("%i ", mat[i][j]);
            fprintf(file, "%d %p\n", 2, &mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(int argc, char **argv){

    if(argc != 3){
        printf("falta arguments\n");
        return 1;
    }

    //obrir fitxers
    FILE *matriuA = fopen(A, "r");
    if(matriuA == NULL){
        printf("oopsie\n");
        return 0;
    }
    FILE *matriuB = fopen(B, "r");
        if(matriuB == NULL){
        printf("oopsie\n");
        return 0;
    }

    FILE *fd = fopen(C, "w");
    if(matriuA == NULL){
        printf("oopsie\n");
        return 0;
    }

    // declarar matrius
    int matA[10][3];
    int matAt[3][10];
    int matAn[10][3];
    int matB[3][15];
    int matBt[15][3];
    int matBn[3][15];
    int matBtAt[15][10];
    int matABt[15][10];
    int matAB[10][15];

    //llegir matrius A i B
    llegirA(matriuA, fd, matA);
    llegirB(matriuB, fd, matB);

    //trasposar A i B
    traspassA(fd, matA, matAt);
    traspassB(fd, matB, matBt);

    //propietat de les trasposades
    multiplyAB(fd, matA, matB, matAB);
    traspassAB(fd, matAB, matABt);
    multiplyBtAt(fd, matBt, matAt, matBtAt);

    if (compare(fd, matABt, matBtAt)) {
        printf("oleeee\n");
    } 

    //negar A i B
    negateA(fd, matA, matAn);
    negateB(fd, matB, matBn);

    //producte de -A i -B
    multiplyAB(fd, matAn, matBn, matAB);
    
    //mostrar per pantalla les 8 matrius
    printAAn(fd, matA);
    printBBn(fd, matB);
    printAt(fd, matAt);
    printBt(fd, matBt);
    printAAn(fd, matAn);
    printBBn(fd, matBn);
    printPropietat(fd, matABt);
    printAB(fd, matAB);

    //tancar fitxers
    fclose(matriuA);
    fclose(matriuB);
    fclose(fd);
    return 0;
}